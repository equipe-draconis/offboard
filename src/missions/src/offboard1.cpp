/**
 * @brief Offboard control example for single drone (px4_1)
 */

#include <px4_msgs/msg/offboard_control_mode.hpp>
#include <px4_msgs/msg/trajectory_setpoint.hpp>
#include <px4_msgs/msg/vehicle_command.hpp>
#include <px4_msgs/msg/vehicle_control_mode.hpp>
#include <px4_msgs/msg/vehicle_local_position.hpp>
#include <px4_msgs/msg/arming_check_request.hpp>
#include <px4_msgs/msg/arming_check_reply.hpp>

#include <rclcpp/rclcpp.hpp>
#include <stdint.h>

#include <chrono>
#include <iostream>
#include <cmath>

using namespace std::chrono;
using namespace std::chrono_literals;
using namespace px4_msgs::msg;

enum class State {
    INIT_OFFBOARD,
    WAIT_FOR_ARM,
    FIRST_SETPOINTS,
    SECOND_SETPOINTS,
    THIRD_SETPOINTS,
    HOME,
    FAILSAFE
};

class OffboardControl : public rclcpp::Node
{
public:
    OffboardControl() : Node("offboard_control"), state_(State::INIT_OFFBOARD)
    {
        // Publishers para px4_1
        offboard_control_mode_publisher_ = this->create_publisher<OffboardControlMode>("/px4_1/fmu/in/offboard_control_mode", 10);
        trajectory_setpoint_publisher_   = this->create_publisher<TrajectorySetpoint>("/px4_1/fmu/in/trajectory_setpoint", 10);
        vehicle_command_publisher_       = this->create_publisher<VehicleCommand>("/px4_1/fmu/in/vehicle_command", 10);
         
        arming_check_reply_pub_ = this->create_publisher<ArmingCheckReply>(
            "/px4_1/fmu/in/arming_check_reply", 10);

        // Configuração de QoS para leitura do tópico de posição local
        auto qos = rclcpp::QoS(rclcpp::KeepLast(10))
            .best_effort()
            .durability_volatile();

        local_position_subscriber_ = this->create_subscription<VehicleLocalPosition>(
            "/px4_1/fmu/out/vehicle_local_position_v1", qos,
            [this](const VehicleLocalPosition::SharedPtr msg) {
                this->local_position_callback(msg);
            });

        //         // Subscritor da requisição enviada pelo PX4
        // arming_check_request_sub_ = this->create_subscription<ArmingCheckRequest>(
        //     "/fmu/out/arming_check_request", rclcpp::QoS(10).best_effort(),
        //     std::bind(&OffboardControl::armingCheckCallback, this, std::placeholders::_1));

     

        offboard_setpoint_counter_ = 0;

        auto timer_callback = [this]() -> void {
            // Heartbeat contínuo para manter o modo Offboard ativo
            publish_offboard_control_mode();

            switch (state_) {
            
            case State::INIT_OFFBOARD:
                // Envia setpoint inicial de hover para o PX4 aceitar o modo Offboard
                send_position_setpoint(0.0f, 0.0f, -5.0f, 0.0f);
                
                if (offboard_setpoint_counter_ >= 10) {
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

        timer_ = this->create_wall_timer(100ms, timer_callback);
    }

    void arm();
    void disarm();
    bool has_reached_target(float target_x, float target_y, float target_z, float tolerance = 0.5f);

private:
    rclcpp::TimerBase::SharedPtr timer_;

    rclcpp::Publisher<OffboardControlMode>::SharedPtr offboard_control_mode_publisher_;
    rclcpp::Publisher<TrajectorySetpoint>::SharedPtr trajectory_setpoint_publisher_;
    rclcpp::Publisher<ArmingCheckReply>::SharedPtr arming_check_reply_pub_;
    rclcpp::Publisher<VehicleCommand>::SharedPtr vehicle_command_publisher_;
    rclcpp::Subscription<VehicleLocalPosition>::SharedPtr local_position_subscriber_;
    rclcpp::Subscription<ArmingCheckRequest>::SharedPtr arming_check_request_sub_;

    VehicleLocalPosition current_position_{};
    bool has_position_data_{false};

    State state_;
    uint64_t offboard_setpoint_counter_;

    void publish_offboard_control_mode();
    void publish_vehicle_command(uint16_t command, float param1 = 0.0, float param2 = 0.0);
    void local_position_callback(const VehicleLocalPosition::SharedPtr msg);
    void send_position_setpoint(float x, float y, float z, float yaw);
};

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

int main(int argc, char *argv[])
{
    std::cout << "Iniciando no de controle offboard (px4_1)..." << std::endl;
    setvbuf(stdout, NULL, _IONBF, BUFSIZ);
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<OffboardControl>());

    rclcpp::shutdown();
    return 0;
}