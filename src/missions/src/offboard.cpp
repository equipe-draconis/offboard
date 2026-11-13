#include "offboard.h"



void OffboardControl::arm()
{
    publish_vehicle_command(VehicleCommand::VEHICLE_CMD_COMPONENT_ARM_DISARM, 1.0);
    RCLCPP_INFO(this->get_logger(), "Comando de armar enviado.");
}

void OffboardControl::disarm()
{
    publish_vehicle_command(VehicleCommand::VEHICLE_CMD_COMPONENT_ARM_DISARM, 0.0);
    RCLCPP_INFO(this->get_logger(), "Comando de desarme enviado.");
}

void OffboardControl::publish_offboard_control_mode()
{
    OffboardControlMode msg{};
    msg.position = true;
    msg.velocity = false;
    msg.acceleration = false;
    msg.attitude = false;
    msg.body_rate = false;
    msg.timestamp = this->get_clock()->now().nanoseconds() / 1000;
    offboard_control_mode_publisher_->publish(msg);
}


void OffboardControl::publish_offboard_control_mode_velocity()
{
    OffboardControlMode msg{};
    msg.position = false;    // Falso: Não estamos mandando coordenadas XYZ
    msg.velocity = true;     // Verdadeiro: PX4 agora espera velocidades!
    msg.acceleration = false;
    msg.attitude = false;
    msg.body_rate = false;
    msg.timestamp = this->get_clock()->now().nanoseconds() / 1000;
    offboard_control_mode_publisher_->publish(msg);
}

void OffboardControl::send_velocity_setpoint(float vx, float vy, float vz, float yawspeed)
{
    TrajectorySetpoint msg{};

    // Regra de ouro do PX4: Se o modo é velocidade, a posição DEVE ser preenchida com NaN
    msg.position = {std::nanf(""), std::nanf(""), std::nanf("")};

    // Coordenadas PX4 são NED (North, East, Down):
    msg.velocity[0] = 1.5;   // Velocidade para o Norte (m/s) -> Anda para frente
    msg.velocity[1] = 0.0;   // Velocidade para o Leste (m/s)
    msg.velocity[2] = -1.0;  // Velocidade para Baixo (m/s) -> SINAL NEGATIVO SOBE! (Sobe a 1 m/s)

    msg.yawspeed = 0.0;      // Velocidade de rotação angular (rad/s)
    
    msg.timestamp = this->get_clock()->now().nanoseconds() / 1000;
    trajectory_setpoint_publisher_->publish(msg);
}


void OffboardControl::send_position_setpoint(float x, float y, float z, float yaw)
{
    TrajectorySetpoint msg{};
    msg.position = {x, y, z};
    msg.yaw = yaw;
    msg.timestamp = this->get_clock()->now().nanoseconds() / 1000;
    trajectory_setpoint_publisher_->publish(msg);
}

void OffboardControl::publish_vehicle_command(uint16_t command, float param1, float param2)
{
    VehicleCommand msg{};
    msg.param1 = param1;
    msg.param2 = param2;
    msg.command = command;
    msg.target_system = 1;
    msg.target_component = 1;
    msg.source_system = 1;
    msg.source_component = 1;
    msg.from_external = true;
    msg.timestamp = this->get_clock()->now().nanoseconds() / 1000;
    vehicle_command_publisher_->publish(msg);
}

void OffboardControl::local_position_callback(const VehicleLocalPosition::SharedPtr msg) 
{
    current_position_ = *msg;
    has_position_data_ = true;

    RCLCPP_INFO_THROTTLE(
        this->get_logger(),
        *this->get_clock(),
        2000,
        "[px4_1] Posição Atual -> X: %.2f | Y: %.2f | Z: %.2f",
        msg->x, msg->y, msg->z
    );
}

bool OffboardControl::has_reached_target(float target_x, float target_y, float target_z, float tolerance)
{
    if (!has_position_data_) {
        return false;
    }

    float dx = current_position_.x - target_x;
    float dy = current_position_.y - target_y;
    float dz = current_position_.z - target_z;

    float distance = std::sqrt(dx * dx + dy * dy + dz * dz);

    RCLCPP_INFO_THROTTLE(
        this->get_logger(), *this->get_clock(), 2000,
        "[px4_1] Alvo: (%.1f, %.1f, %.1f) | Atual: (%.1f, %.1f, %.1f) | Dist: %.2fm (Tol: %.1fm)",
        target_x, target_y, target_z,
        current_position_.x, current_position_.y, current_position_.z, distance, tolerance
    );

    return distance <= tolerance;
}

void OffboardControl::set_home_position()
{
    HomePosition msg;

    // Define as coordenadas locais
    msg.x = current_position_.x;
    msg.y = current_position_.y;
    msg.z = current_position_.z;

    // Flags de validação da posição
    msg.valid_lpos = true;

    // Timestamp em microssegundos (padrão uORB / PX4)
    msg.timestamp = this->get_clock()->now().nanoseconds() / 1000;

    home_position_publisher_->publish(msg);
}

// // Função callback que responde à checagem do PX4
// void responderArmingCheck(const px4_msgs::msg::ArmingCheckRequest::SharedPtr request) 
// {
//     auto reply = px4_msgs::msg::ArmingCheckReply();
    
//     reply.timestamp = this->get_clock()->now().nanoseconds() / 1000;
//     reply.request_id = request->request_id; // Vincula a resposta ao ID da requisição
//     reply.registration_id = minha_registration_id_; // ID obtido ao registrar o componente no PX4

//     // 1. Defina suas condições de Failsafe / Segurança aqui:
//     bool topico_ativo = checarTimeoutTopicos(); 
//     bool dados_validos = (this->posicao_local_valida_ && this->bateria_ok_);

//     // 2. Se tudo estiver OK, autoriza o PX4
//     if (topico_ativo && dados_validos) {
//         reply.can_arm_and_run = true;
//         reply.health_component_healthy = true;
//         reply.num_events = 0;
//     } 
//     // 3. Se alguma condição falhar, nega a autorização / força Failsafe
//     else {
//         reply.can_arm_and_run = false;         // Impede o armamento
//         reply.health_component_healthy = false; // Sinaliza componente com falha
        
//         // Define evento de erro no registro do PX4
//         reply.num_events = 1;
//         reply.events[0].event_id = 0x0001; // ID de evento customizado do seu nó
//     }

//     // Envia a resposta de volta ao PX4
//     this->arming_check_reply_pub_->publish(reply);
// }

void OffboardControl::timer_callback() 
{
    // Heartbeat contínuo para manter o modo Offboard ativo
    // publish_offboard_control_mode();

    publish_offboard_control_mode_velocity();

    switch (state_) {
    
    case State::INIT_OFFBOARD:
        // Envia setpoint inicial de hover para o PX4 aceitar o modo Offboard
        send_position_setpoint(0.0f, 0.0f, -5.0f, 0.0f);
        
        if (offboard_setpoint_counter_ >= 10 ) {
            RCLCPP_INFO(this->get_logger(), "PASSO 1: Solicitando MODO OFFBOARD e ARMANDO...");
            this->publish_vehicle_command(VehicleCommand::VEHICLE_CMD_DO_SET_MODE, 1, 6);
            this->arm();
            state_ = State::WAIT_FOR_ARM;
        } else {
            RCLCPP_ERROR(this->get_logger(), "Condições de ArmingCheck violadas! Não enviando comando de Arm.");
            state_ = State::FAILSAFE;
        }

        break;

    case State::WAIT_FOR_ARM:
        send_position_setpoint(0.0f, 0.0f, -5.0f, 0.0f);

        if (offboard_setpoint_counter_ >= 30) {
            RCLCPP_INFO(this->get_logger(), "PASSO 2: Armado! Indo para o PRIMEIRO SETPOINT (Ponto A)...");
            state_ = State::FIRST_SETPOINTS;
        }
        break;

    case State::FIRST_SETPOINTS:
        send_position_setpoint(0.0f, 2.5f, -5.0f, 0.0f);

        if (has_reached_target(0.0f, 2.5f, -5.0f, 0.5f)) {
            RCLCPP_INFO(this->get_logger(), "PASSO 3: Chegou ao Ponto A! Indo para o SEGUNDO SETPOINT (Ponto B)...");
            state_ = State::SECOND_SETPOINTS;
        }
        break;

    case State::SECOND_SETPOINTS:
        send_position_setpoint(5.0f, 5.0f, -5.0f, 0.0f);

        if (has_reached_target(5.0f, 5.0f, -5.0f, 0.5f)) {
            RCLCPP_INFO(this->get_logger(), "PASSO 4: Chegou ao Ponto B! Indo para o TERCEIRO SETPOINT (Ponto C)...");
            state_ = State::THIRD_SETPOINTS;
        }
        break;

    case State::THIRD_SETPOINTS:
        send_position_setpoint(10.0f, 5.0f, -5.0f, 0.0f);

        if (has_reached_target(10.0f, 5.0f, -5.0f, 0.5f)) {
            RCLCPP_INFO(this->get_logger(), "PASSO 5: Chegou ao Ponto C! Voltando para casa...");
            state_ = State::HOME;
        }
        break;

    case State::HOME:
        send_position_setpoint(0.0f, 0.0f, -5.0f, 0.0f);

        if (has_reached_target(0.0f, 0.0f, -5.0f, 0.5f)) {
            RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 5000, 
                "PASSO 6: Drone retornou ao ponto inicial com sucesso!");
        }
        break;

    case State::FAILSAFE:
        send_position_setpoint(0.0f, 0.0f, 0.0f, 0.0f);

        if (has_reached_target(0.0f, 0.0f, 0.0f, 0.0f)) {
            RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 5000, 
                "PASSO FAILSAFE: emergencia desarmando o drone");
            this->disarm();
        }
        break;


    }

    offboard_setpoint_counter_++;
    };
