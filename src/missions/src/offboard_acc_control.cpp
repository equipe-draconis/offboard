#include <px4_msgs/msg/offboard_control_mode.hpp>
#include <px4_msgs/msg/trajectory_setpoint.hpp>
#include <px4_msgs/msg/vehicle_command.hpp>
#include <px4_msgs/msg/vehicle_control_mode.hpp>
#include <rclcpp/rclcpp.hpp>
#include <stdint.h>

#include <chrono>
#include <iostream>
#include <cmath> // Para usar std::nanf

using namespace std::chrono;
using namespace std::chrono_literals;
using namespace px4_msgs::msg;

class OffboardControl : public rclcpp::Node
{
public:
    OffboardControl() : Node("offboard_control")
    {
        offboard_control_mode_publisher_ = this->create_publisher<OffboardControlMode>("/px4_3/fmu/in/offboard_control_mode", 10);
		trajectory_setpoint_publisher_ = this->create_publisher<TrajectorySetpoint>("/px4_3/fmu/in/trajectory_setpoint", 10);
		vehicle_command_publisher_ = this->create_publisher<VehicleCommand>("/px4_3/fmu/in/vehicle_command", 10);
        
        offboard_setpoint_counter_ = 0;
        auto timer_callback = [this]() -> void {
            publish_offboard_control_mode();
            publish_trajectory_setpoint();

            if (offboard_setpoint_counter_ >= 10) {
                RCLCPP_INFO(this->get_logger(), "FORÇANDO OFFBOARD + ARM");
                this->publish_vehicle_command(VehicleCommand::VEHICLE_CMD_DO_SET_MODE, 1, 6);
                this->arm();
            }

            offboard_setpoint_counter_++;
        };
        timer_ = this->create_wall_timer(100ms, timer_callback);
    }

    void arm();
    void disarm();

private:
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<OffboardControlMode>::SharedPtr offboard_control_mode_publisher_;
    rclcpp::Publisher<TrajectorySetpoint>::SharedPtr trajectory_setpoint_publisher_;
    rclcpp::Publisher<VehicleCommand>::SharedPtr vehicle_command_publisher_;

    uint64_t offboard_setpoint_counter_;

    void publish_offboard_control_mode();
    void publish_trajectory_setpoint();
    void publish_vehicle_command(uint16_t command, float param1 = 0.0, float param2 = 0.0);
};

void OffboardControl::arm()
{
    publish_vehicle_command(VehicleCommand::VEHICLE_CMD_COMPONENT_ARM_DISARM, 1.0);
    RCLCPP_INFO(this->get_logger(), "Arm command send");
}

void OffboardControl::disarm()
{
    publish_vehicle_command(VehicleCommand::VEHICLE_CMD_COMPONENT_ARM_DISARM, 0.0);
    RCLCPP_INFO(this->get_logger(), "Disarm command send");
}

/**
 * @brief ALTERADO: Ativa apenas o controle de aceleração
 */
void OffboardControl::publish_offboard_control_mode()
{
    OffboardControlMode msg{};
    msg.position = false;    
    msg.velocity = false;     
    msg.acceleration = true; // Verdadeiro: PX4 agora espera vetor de aceleração!
    msg.attitude = false;
    msg.body_rate = false;
    msg.timestamp = this->get_clock()->now().nanoseconds() / 1000;
    offboard_control_mode_publisher_->publish(msg);
}

/**
 * @brief ALTERADO: Envia acelerações no padrão NED (m/s²)
 */
void OffboardControl::publish_trajectory_setpoint()
{
    TrajectorySetpoint msg{};

    // Regra de ouro: Se controlamos aceleração, posição E velocidade DEVEM ser NaN
    msg.position = {std::nanf(""), std::nanf(""), std::nanf("")};
    msg.velocity = {std::nanf(""), std::nanf(""), std::nanf("")};

    // Coordenadas PX4 são NED (North, East, Down) em m/s²:
    msg.acceleration[0] = 0.0;   // Sem aceleração para o Norte
    msg.acceleration[1] = 0.0;   // Sem aceleração para o Leste
    msg.acceleration[2] = -0.5;  // Aceleração para CIMA (Z negativo) de 0.5 m/s²
    
    // Nota: O PX4 cuidará internamente da compensação da gravidade (g) se o estimador estiver saudável.

    msg.yawspeed = 0.0; // Mantém sem girar
    
    msg.timestamp = this->get_clock()->now().nanoseconds() / 1000;
    trajectory_setpoint_publisher_->publish(msg);
}

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
}

int main(int argc, char *argv[])
{
    std::cout << "Starting offboard acceleration control node..." << std::endl;
    setvbuf(stdout, NULL, _IONBF, BUFSIZ);
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<OffboardControl>());
    rclcpp::shutdown();
    return 0;
}