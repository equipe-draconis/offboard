/**
 * @brief Offboard control example
 * @file offboard_control.cpp
 * @addtogroup examples
 * @author Mickey Cowden <info@cowden.tech>
 * @author Nuno Marques <nuno.marques@dronesolutions.io>
 */

#include <px4_msgs/msg/offboard_control_mode.hpp>
#include <px4_msgs/msg/trajectory_setpoint.hpp>
#include <px4_msgs/msg/vehicle_command.hpp>
#include <px4_msgs/msg/vehicle_control_mode.hpp>
#include <px4_msgs/msg/vehicle_local_position.hpp>
#include <rclcpp/rclcpp.hpp>
#include <stdint.h>

#include <chrono>
#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std::chrono;
using namespace std::chrono_literals;
using namespace px4_msgs::msg;

// CORRIGIDO: Itens do enum separados por vírgula e terminados em ';' no final da estrutura
enum class State {
    INIT_OFFBOARD,
    WAIT_FOR_ARM,
    FIRST_SETPOINTS,
    SECOND_SETPOINTS,
	THIRD_SETPOINTS,
    HOME
};

class OffboardControl : public rclcpp::Node
{
public:
    OffboardControl() : Node("offboard_control"), state_(State::INIT_OFFBOARD)
    {
        offboard_control_mode_publisher_ = this->create_publisher<OffboardControlMode>("/px4_1/fmu/in/offboard_control_mode", 10);
        offboard_control_mode_publisher2_ = this->create_publisher<OffboardControlMode>("/px4_2/fmu/in/offboard_control_mode", 10);
        offboard_control_mode_publisher3_ = this->create_publisher<OffboardControlMode>("/px4_3/fmu/in/offboard_control_mode", 10);

        trajectory_setpoint_publisher_ = this->create_publisher<TrajectorySetpoint>("/px4_1/fmu/in/trajectory_setpoint", 10);
        trajectory_setpoint_publisher2_ = this->create_publisher<TrajectorySetpoint>("/px4_2/fmu/in/trajectory_setpoint", 10);
        trajectory_setpoint_publisher3_ = this->create_publisher<TrajectorySetpoint>("/px4_3/fmu/in/trajectory_setpoint", 10);
        
        vehicle_command_publisher_ = this->create_publisher<VehicleCommand>("/px4_1/fmu/in/vehicle_command", 10);
        vehicle_command_publisher2_ = this->create_publisher<VehicleCommand>("/px4_2/fmu/in/vehicle_command", 10);
        vehicle_command_publisher3_ = this->create_publisher<VehicleCommand>("/px4_3/fmu/in/vehicle_command", 10);
        
		// Definição da QoS idêntica à publicada pela Micro-XRCE-DDS Agent
		auto qos = rclcpp::QoS(rclcpp::KeepLast(10))
			.best_effort()
			.durability_volatile();

		// local_position_subscriber1_ = this->create_subscription<VehicleLocalPosition>(
		// 	"/px4_1/fmu/out/vehicle_local_position", qos,
		// 	[this](const VehicleLocalPosition::SharedPtr msg) {
		// 		this->local_position_callback(msg, "px4_1");
		// 	});

		local_position_subscriber2_ = this->create_subscription<VehicleLocalPosition>(
			"/px4_2/fmu/out/vehicle_local_position_v1", qos,
			[this](const VehicleLocalPosition::SharedPtr msg) {
				this->local_position_callback(msg, "px4_2");
			});

		local_position_subscriber3_ = this->create_subscription<VehicleLocalPosition>(
			"/px4_3/fmu/out/vehicle_local_position_v1", qos,
			[this](const VehicleLocalPosition::SharedPtr msg) {
				this->local_position_callback(msg, "px4_3");
			});

        offboard_setpoint_counter_ = 0;

        auto timer_callback = [this]() -> void {
            // 1. OBRIGATÓRIO: Mantém o sinal de heartbeat para o PX4 não sair de Offboard
            publish_offboard_control_mode();

            switch (state_) {
            
            // PASSO 1: Envia setpoints iniciais em hover para o PX4 aceitar a troca de modo
            case State::INIT_OFFBOARD:
                publish_trajectory_setpoint(); // Setpoint padrão de hover
                
                if (offboard_setpoint_counter_ >= 10) {
                    RCLCPP_INFO(this->get_logger(), "PASSO 1: Forçando MODO OFFBOARD e ARMANDO...");
                    
                    this->publish_vehicle_command(VehicleCommand::VEHICLE_CMD_DO_SET_MODE, 1, 6);
                    this->arm();
                    
                    state_ = State::WAIT_FOR_ARM;
                }
                break;

            // PASSO 2: Aguarda estabilização pós-armamento
            case State::WAIT_FOR_ARM:
                
                if (offboard_setpoint_counter_ >= 30) {
                    RCLCPP_INFO(this->get_logger(), "PASSO 2: Armados! Enviando PRIMEIRO SETPOINT (Ponto A)...");
                    state_ = State::FIRST_SETPOINTS;
                }
                break;

			case State::FIRST_SETPOINTS:
			// send_position_setpoint(1, 0.0f, 0.0f, -5.0f, 0.0f);
			send_position_setpoint_2(0.0f, 2.5f, -5.0f, -6.28f);
            // send_position_setpoint(2, 0.0f, 2.5f, -5.0f, -6.28f);
			send_position_setpoint_3(2.5f, 0.0f, -5.0f, -3.14f);

			// LOG DE DEBUG PARA IMPRIMIR NO TERMINAL A CADA 2 SEGUNDOS
			RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 2000,
				"Aguardando Chegada -> Drone 2 Ok? %s | Drone 3 Ok? %s",
				has_reached_target("px4_2", 0.0f, 2.5f, -5.0f, 0.5f) ? "SIM" : "NAO",
				has_reached_target("px4_3", 2.5f, 0.0f, -5.0f, 0.5f) ? "SIM" : "NAO"
			);

			if (has_reached_target("px4_2", 0.0f, 2.5f, -5.0f, 0.5f) && 
				has_reached_target("px4_3", 2.5f, 0.0f, -5.0f, 0.5f)) 
			{
				RCLCPP_INFO(this->get_logger(), "PASSO 3: Chegaram na Posição A! Indo para NOVOS SETPOINTS (Ponto B)...");
				state_ = State::SECOND_SETPOINTS;
			}
			break;

            // PASSO 4: Envia a NOVA posição (Ponto B)
            case State::SECOND_SETPOINTS:
                this->send_position_setpoint_2(5.0f, 5.0f, -5.0f, 0.0f);
                // this->send_position_setpoint(2, 5.0f, 5.0f, -5.0f, -0.0f);
                this->send_position_setpoint_3(5.0f, -2.5f, -5.0f, 0.0f);

                if (has_reached_target("px4_2", 5.0f, 5.0f, -5.0f) && 
                    has_reached_target("px4_3", 5.0f, -2.5f, -5.0f)) 
                {
                    RCLCPP_INFO(this->get_logger(), "PASSO 4: Chegaram ao Ponto B! Voltando para casa...");
                    state_ = State::HOME;
                }
                break;

			     // PASSO 4: Envia a NOVA posição (Ponto B)
            case State::THIRD_SETPOINTS:
                this->send_position_setpoint_2(10.0f, 5.0f, -5.0f, 0.0f);
                this->send_position_setpoint_3(20.0f, -2.5f, -5.0f, 0.0f);

                if (has_reached_target("px4_2", 10.0f, 5.0f, -5.0f) && 
                    has_reached_target("px4_3", 20.0f, -2.5f, -5.0f)) 
                {
                    RCLCPP_INFO(this->get_logger(), "PASSO 4: Chegaram ao Ponto B! Voltando para casa...");
                    state_ = State::HOME;
                }
                break;

            // PASSO 5: Retorna à Posição Inicial
            case State::HOME:
                this->send_position_setpoint_2(0.0f, 0.0f, -5.0f, 0.0f);
                this->send_position_setpoint_3(0.0f, 0.0f, -5.0f, 0.0f);

                if (has_reached_target("px4_2", 0.0f, 0.0f, -5.0f) && 
                    has_reached_target("px4_3", 0.0f, 0.0f, -5.0f)) 
                {
                    RCLCPP_INFO(this->get_logger(), "PASSO 5: Voltaram pra casa com sucesso!");
                }
                break;
            } // Fechamento correto do switch

            offboard_setpoint_counter_++;
        };

        timer_ = this->create_wall_timer(100ms, timer_callback);
    }

    bool has_reached_target(const std::string &drone_id, float target_x, float target_y, float target_z, float tolerance = 0.3f);
    void arm();
    void disarm();

private:
    rclcpp::TimerBase::SharedPtr timer_;

    rclcpp::Publisher<OffboardControlMode>::SharedPtr offboard_control_mode_publisher_;
    rclcpp::Publisher<OffboardControlMode>::SharedPtr offboard_control_mode_publisher2_;
    rclcpp::Publisher<OffboardControlMode>::SharedPtr offboard_control_mode_publisher3_;

    rclcpp::Publisher<TrajectorySetpoint>::SharedPtr trajectory_setpoint_publisher_;
    rclcpp::Publisher<TrajectorySetpoint>::SharedPtr trajectory_setpoint_publisher2_;
    rclcpp::Publisher<TrajectorySetpoint>::SharedPtr trajectory_setpoint_publisher3_;

    rclcpp::Publisher<VehicleCommand>::SharedPtr vehicle_command_publisher_;
    rclcpp::Publisher<VehicleCommand>::SharedPtr vehicle_command_publisher2_;
    rclcpp::Publisher<VehicleCommand>::SharedPtr vehicle_command_publisher3_;

    std::unordered_map<std::string, px4_msgs::msg::VehicleLocalPosition> current_positions_;

    rclcpp::Subscription<VehicleLocalPosition>::SharedPtr local_position_subscriber2_;
    rclcpp::Subscription<VehicleLocalPosition>::SharedPtr local_position_subscriber3_;

    std::atomic<uint64_t> timestamp_;
    State state_;

    uint64_t offboard_setpoint_counter_;

    void publish_offboard_control_mode();
    void publish_trajectory_setpoint();
    void publish_vehicle_command(uint16_t command, float param1 = 0.0, float param2 = 0.0);
    void local_position_callback(const px4_msgs::msg::VehicleLocalPosition::SharedPtr msg, const std::string &drone_id);
    void send_position_setpoint_2(float x, float y, float z, float yaw);
    void send_position_setpoint_3(float x, float y, float z, float yaw);
    // void send_position_setpoint(uint8_t id, float x, float y, float z, float yaw);
};

void OffboardControl::arm()
{
    publish_vehicle_command(VehicleCommand::VEHICLE_CMD_COMPONENT_ARM_DISARM, 1.0);
    RCLCPP_INFO(this->get_logger(), "Arm command sent");
}

void OffboardControl::disarm()
{
    publish_vehicle_command(VehicleCommand::VEHICLE_CMD_COMPONENT_ARM_DISARM, 0.0);
    RCLCPP_INFO(this->get_logger(), "Disarm command sent");
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
    offboard_control_mode_publisher2_->publish(msg);
    offboard_control_mode_publisher3_->publish(msg);
}

void OffboardControl::publish_trajectory_setpoint()
{
    uint64_t now = this->get_clock()->now().nanoseconds() / 1000;

    TrajectorySetpoint msg{};
    msg.position = {0.0, 0.0, -5.0};
    msg.yaw = -3.14;
    msg.timestamp = now;
    trajectory_setpoint_publisher_->publish(msg);

    TrajectorySetpoint msg2{};
    msg2.position = {0.0, 2.5, -5.0};
    msg2.yaw = -6.28;
    msg2.yawspeed = 0.5;
    msg2.timestamp = now;
    trajectory_setpoint_publisher2_->publish(msg2);

    TrajectorySetpoint msg3{};
    msg3.position = {2.5, 0.0, -5.0};
    msg3.yaw = -3.14;
    msg3.timestamp = now;
    trajectory_setpoint_publisher3_->publish(msg3);
}

void OffboardControl::send_position_setpoint_2(float x, float y, float z, float yaw)
{
    TrajectorySetpoint msg{};
    msg.position = {x, y, z};
    msg.yaw = yaw;
    msg.timestamp = this->get_clock()->now().nanoseconds() / 1000;
    trajectory_setpoint_publisher2_->publish(msg);
}

void OffboardControl::send_position_setpoint_3(float x, float y, float z, float yaw)
{
    TrajectorySetpoint msg{};
    msg.position = {x, y, z};
    msg.yaw = yaw;
    msg.timestamp = this->get_clock()->now().nanoseconds() / 1000;
    trajectory_setpoint_publisher3_->publish(msg);
}
// void OffboardControl::send_position_setpoint(uint8_t id, float x, float y, float z, float yaw)
// {
//     TrajectorySetpoint msg{};
//     msg.position = {x, y, z};
//     msg.yaw = yaw;
//     msg.timestamp = this->get_clock()->now().nanoseconds() / 1000;

//     switch (id)
//     {
//     case 1:
//         trajectory_setpoint_publisher_->publish(msg);
//         break;
//     case 2:
//         trajectory_setpoint_publisher2_->publish(msg);
//         break;
//     // case 3:
//     //     trajectory_setpoint_publisher3_->publish(msg);
//     //     break;
//     }

// }

void OffboardControl::publish_vehicle_command(uint16_t command, float param1, float param2)
{
    VehicleCommand msg{};
    msg.param1 = param1;
    msg.param2 = param2;
    msg.command = command;
    msg.target_system = 0;
    msg.target_component = 1;
    msg.source_system = 1;
    msg.source_component = 1;
    msg.from_external = true;
    msg.timestamp = this->get_clock()->now().nanoseconds() / 1000;
    
    vehicle_command_publisher_->publish(msg);
    vehicle_command_publisher2_->publish(msg);
    vehicle_command_publisher3_->publish(msg);
}

void OffboardControl::local_position_callback(
    const px4_msgs::msg::VehicleLocalPosition::SharedPtr msg, 
    const std::string &drone_id) 
{
    // REMOVIDO: a trava de xy_valid / z_valid que descartava as mensagens silenciosamente.
    
    // Armazena a posição atualizada no mapa
    current_positions_[drone_id] = *msg;

    // Imprime no terminal a cada 2 segundos para você CONFIRMAR que está recebendo
    RCLCPP_INFO_THROTTLE(
        this->get_logger(),
        *this->get_clock(),
        2000,
        "[%s] Lendo Pos -> X: %.2f | Y: %.2f | Z: %.2f",
        drone_id.c_str(), msg->x, msg->y, msg->z
    );
}

bool OffboardControl::has_reached_target(const std::string &drone_id, float target_x, float target_y, float target_z, float tolerance)
{
    auto it = current_positions_.find(drone_id);
    if (it == current_positions_.end()) {
        return false;
    }

    float dx = it->second.x - target_x;
    float dy = it->second.y - target_y;
    float dz = it->second.z - target_z;

    // Distância total em 3D
    float distance = std::sqrt(dx * dx + dy * dy + dz * dz);

    // LOG para você enxergar a distância exata no terminal durante o teste
    RCLCPP_INFO_THROTTLE(
        this->get_logger(), *this->get_clock(), 1500,
        "[%s] Target: (%.1f, %.1f, %.1f) | Atual: (%.1f, %.1f, %.1f) | Dist: %.2fm (Tol: %.1fm)",
        drone_id.c_str(), target_x, target_y, target_z,
        it->second.x, it->second.y, it->second.z, distance, tolerance
    );

    return distance <= tolerance;
}

int main(int argc, char *argv[])
{
    std::cout << "Starting offboard control node..." << std::endl;
    setvbuf(stdout, NULL, _IONBF, BUFSIZ);
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<OffboardControl>());

    rclcpp::shutdown();
    return 0;
}