/**
 * @brief Offboard control example for 5 drones swarm
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
        // Publishers
        offboard_control_mode_publisher_  = this->create_publisher<OffboardControlMode>("/px4_1/fmu/in/offboard_control_mode", 10);
        offboard_control_mode_publisher2_ = this->create_publisher<OffboardControlMode>("/px4_2/fmu/in/offboard_control_mode", 10);
        offboard_control_mode_publisher3_ = this->create_publisher<OffboardControlMode>("/px4_3/fmu/in/offboard_control_mode", 10);
        offboard_control_mode_publisher4_ = this->create_publisher<OffboardControlMode>("/px4_4/fmu/in/offboard_control_mode", 10);
        offboard_control_mode_publisher5_ = this->create_publisher<OffboardControlMode>("/px4_5/fmu/in/offboard_control_mode", 10);

        trajectory_setpoint_publisher_  = this->create_publisher<TrajectorySetpoint>("/px4_1/fmu/in/trajectory_setpoint", 10);
        trajectory_setpoint_publisher2_ = this->create_publisher<TrajectorySetpoint>("/px4_2/fmu/in/trajectory_setpoint", 10);
        trajectory_setpoint_publisher3_ = this->create_publisher<TrajectorySetpoint>("/px4_3/fmu/in/trajectory_setpoint", 10);
        trajectory_setpoint_publisher4_ = this->create_publisher<TrajectorySetpoint>("/px4_4/fmu/in/trajectory_setpoint", 10);
        trajectory_setpoint_publisher5_ = this->create_publisher<TrajectorySetpoint>("/px4_5/fmu/in/trajectory_setpoint", 10);
        
        vehicle_command_publisher_  = this->create_publisher<VehicleCommand>("/px4_1/fmu/in/vehicle_command", 10);
        vehicle_command_publisher2_ = this->create_publisher<VehicleCommand>("/px4_2/fmu/in/vehicle_command", 10);
        vehicle_command_publisher3_ = this->create_publisher<VehicleCommand>("/px4_3/fmu/in/vehicle_command", 10);
        vehicle_command_publisher4_ = this->create_publisher<VehicleCommand>("/px4_4/fmu/in/vehicle_command", 10);
        vehicle_command_publisher5_ = this->create_publisher<VehicleCommand>("/px4_5/fmu/in/vehicle_command", 10);
        
        // Definição da QoS idêntica à publicada pela Micro-XRCE-DDS Agent
        auto qos = rclcpp::QoS(rclcpp::KeepLast(10))
            .best_effort()
            .durability_volatile();

        // Subscribers habilitados para todos os 5 drones
        local_position_subscriber1_ = this->create_subscription<VehicleLocalPosition>(
            "/px4_1/fmu/out/vehicle_local_position_v1", qos,
            [this](const VehicleLocalPosition::SharedPtr msg) {
                this->local_position_callback(msg, "px4_1");
            });

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

        local_position_subscriber4_ = this->create_subscription<VehicleLocalPosition>(
            "/px4_4/fmu/out/vehicle_local_position_v1", qos,
            [this](const VehicleLocalPosition::SharedPtr msg) {
                this->local_position_callback(msg, "px4_4");
            });

        local_position_subscriber5_ = this->create_subscription<VehicleLocalPosition>(
            "/px4_5/fmu/out/vehicle_local_position_v1", qos,
            [this](const VehicleLocalPosition::SharedPtr msg) {
                this->local_position_callback(msg, "px4_5");
            });

        offboard_setpoint_counter_ = 0;

        auto timer_callback = [this]() -> void {
            // Heartbeat constante para não perder modo offboard
            publish_offboard_control_mode();

            switch (state_) {
            
            case State::INIT_OFFBOARD:
                // Decolagem / Hover inicial
                send_position_setpoint(1, 0.0f, 0.0f, -5.0f, 0.0f);
                send_position_setpoint(2, 0.0f, 2.5f, -5.0f, 0.0f);
                send_position_setpoint(3, 2.5f, 0.0f, -5.0f, 0.0f);
                send_position_setpoint(4, 5.0f, 2.5f, -5.0f, 0.0f);
                send_position_setpoint(5, 7.5f, 0.0f, -5.0f, 0.0f);
                
                if (offboard_setpoint_counter_ >= 10) {
                    RCLCPP_INFO(this->get_logger(), "PASSO 1: Forçando MODO OFFBOARD e ARMANDO...");
                    
                    // Altera o modo para OFFBOARD (param1 = 1, param2 = 6)
                    this->publish_vehicle_command_all(VehicleCommand::VEHICLE_CMD_DO_SET_MODE, 1.0f, 6.0f);
                    this->arm();
                    state_ = State::WAIT_FOR_ARM;
                }
                break;

            case State::WAIT_FOR_ARM:
                // Manutenção em Hover até confirmar armamento
                send_position_setpoint(1, 0.0f, 0.0f, -5.0f, 0.0f);
                send_position_setpoint(2, 0.0f, 2.5f, -5.0f, 0.0f);
                send_position_setpoint(3, 2.5f, 0.0f, -5.0f, 0.0f);
                send_position_setpoint(4, 5.0f, 2.5f, -5.0f, 0.0f);
                send_position_setpoint(5, 7.5f, 0.0f, -5.0f, 0.0f);

                if (offboard_setpoint_counter_ >= 30) {
                    RCLCPP_INFO(this->get_logger(), "PASSO 2: Armados! Enviando PRIMEIRO SETPOINT (Ponto A)...");
                    state_ = State::FIRST_SETPOINTS;
                }
                break;

            case State::FIRST_SETPOINTS:
                send_position_setpoint(1, 0.0f, 0.0f, -5.0f, 0.0f);
                send_position_setpoint(2, 0.0f, 2.5f, -5.0f, -6.28f);
                send_position_setpoint(3, 2.5f, 0.0f, -5.0f, -3.14f);
                send_position_setpoint(4, 5.0f, 2.5f, -5.0f, -6.28f);
                send_position_setpoint(5, 7.5f, 0.0f, -5.0f, -3.14f);

                if (has_reached_target("px4_1", 0.0f, 0.0f, -5.0f, 0.5f) &&
                    has_reached_target("px4_2", 0.0f, 2.5f, -5.0f, 0.5f) && 
                    has_reached_target("px4_3", 2.5f, 0.0f, -5.0f, 0.5f) &&
                    has_reached_target("px4_4", 5.0f, 2.5f, -5.0f, 0.5f) &&
                    has_reached_target("px4_5", 7.5f, 0.0f, -5.0f, 0.5f)) 
                {
                    RCLCPP_INFO(this->get_logger(), "PASSO 3: Chegaram na Posição A! Indo para SEGUNDO SETPOINT (Ponto B)...");
                    state_ = State::SECOND_SETPOINTS;
                }
                break;

            case State::SECOND_SETPOINTS:
                send_position_setpoint(1, 2.5f, 0.0f, -5.0f, 0.0f);
                send_position_setpoint(2, 5.0f, 5.0f, -5.0f, 0.0f);
                send_position_setpoint(3, 5.0f, -2.5f, -5.0f, 0.0f);
                send_position_setpoint(4, 7.5f, 5.0f, -5.0f, 0.0f);
                send_position_setpoint(5, 10.0f, -2.5f, -5.0f, 0.0f);

                if (has_reached_target("px4_1", 2.5f, 0.0f, -5.0f, 0.5f) &&
                    has_reached_target("px4_2", 5.0f, 5.0f, -5.0f, 0.5f) && 
                    has_reached_target("px4_3", 5.0f, -2.5f, -5.0f, 0.5f) &&
                    has_reached_target("px4_4", 7.5f, 5.0f, -5.0f, 0.5f) &&
                    has_reached_target("px4_5", 10.0f, -2.5f, -5.0f, 0.5f)) 
                {
                    RCLCPP_INFO(this->get_logger(), "PASSO 4: Chegaram ao Ponto B! Indo para TERCEIRO SETPOINT (Ponto C)...");
                    state_ = State::THIRD_SETPOINTS;
                }
                break;

            case State::THIRD_SETPOINTS:
                send_position_setpoint(1, 5.0f, 0.0f, -5.0f, 0.0f);
                send_position_setpoint(2, 10.0f, 5.0f, -5.0f, 0.0f);
                send_position_setpoint(3, 20.0f, -2.5f, -5.0f, 0.0f);
                send_position_setpoint(4, 15.0f, 5.0f, -5.0f, 0.0f);
                send_position_setpoint(5, 25.0f, -2.5f, -5.0f, 0.0f);

                if (has_reached_target("px4_1", 5.0f, 0.0f, -5.0f, 0.5f) &&
                    has_reached_target("px4_2", 10.0f, 5.0f, -5.0f, 0.5f) && 
                    has_reached_target("px4_3", 20.0f, -2.5f, -5.0f, 0.5f) &&
                    has_reached_target("px4_4", 15.0f, 5.0f, -5.0f, 0.5f) &&
                    has_reached_target("px4_5", 25.0f, -2.5f, -5.0f, 0.5f)) 
                {
                    RCLCPP_INFO(this->get_logger(), "PASSO 5: Chegaram ao Ponto C! Voltando para casa...");
                    state_ = State::HOME;
                }
                break;

            case State::HOME:
                send_position_setpoint(1, 0.0f, 0.0f, -5.0f, 0.0f);
                send_position_setpoint(2, 0.0f, 0.0f, -5.0f, 0.0f);
                send_position_setpoint(3, 0.0f, 0.0f, -5.0f, 0.0f);
                send_position_setpoint(4, 0.0f, 0.0f, -5.0f, 0.0f);
                send_position_setpoint(5, 0.0f, 0.0f, -5.0f, 0.0f);

                if (has_reached_target("px4_1", 0.0f, 0.0f, -5.0f, 0.5f) &&
                    has_reached_target("px4_2", 0.0f, 0.0f, -5.0f, 0.5f) && 
                    has_reached_target("px4_3", 0.0f, 0.0f, -5.0f, 0.5f) &&
                    has_reached_target("px4_4", 0.0f, 0.0f, -5.0f, 0.5f) &&
                    has_reached_target("px4_5", 0.0f, 0.0f, -5.0f, 0.5f)) 
                {
                    RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 5000, "PASSO 6: Todos voltaram pra casa com sucesso!");
                }
                break;
            }

            offboard_setpoint_counter_++;
        };

        timer_ = this->create_wall_timer(100ms, timer_callback);
    }

    bool has_reached_target(const std::string &drone_id, float target_x, float target_y, float target_z, float tolerance = 0.5f);
    void arm();
    void disarm();

private:
    rclcpp::TimerBase::SharedPtr timer_;

    rclcpp::Publisher<OffboardControlMode>::SharedPtr offboard_control_mode_publisher_;
    rclcpp::Publisher<OffboardControlMode>::SharedPtr offboard_control_mode_publisher2_;
    rclcpp::Publisher<OffboardControlMode>::SharedPtr offboard_control_mode_publisher3_;
    rclcpp::Publisher<OffboardControlMode>::SharedPtr offboard_control_mode_publisher4_;
    rclcpp::Publisher<OffboardControlMode>::SharedPtr offboard_control_mode_publisher5_;

    rclcpp::Publisher<TrajectorySetpoint>::SharedPtr trajectory_setpoint_publisher_;
    rclcpp::Publisher<TrajectorySetpoint>::SharedPtr trajectory_setpoint_publisher2_;
    rclcpp::Publisher<TrajectorySetpoint>::SharedPtr trajectory_setpoint_publisher3_;
    rclcpp::Publisher<TrajectorySetpoint>::SharedPtr trajectory_setpoint_publisher4_;
    rclcpp::Publisher<TrajectorySetpoint>::SharedPtr trajectory_setpoint_publisher5_;

    rclcpp::Publisher<VehicleCommand>::SharedPtr vehicle_command_publisher_;
    rclcpp::Publisher<VehicleCommand>::SharedPtr vehicle_command_publisher2_;
    rclcpp::Publisher<VehicleCommand>::SharedPtr vehicle_command_publisher3_;
    rclcpp::Publisher<VehicleCommand>::SharedPtr vehicle_command_publisher4_;
    rclcpp::Publisher<VehicleCommand>::SharedPtr vehicle_command_publisher5_;

    rclcpp::Subscription<VehicleLocalPosition>::SharedPtr local_position_subscriber1_;
    rclcpp::Subscription<VehicleLocalPosition>::SharedPtr local_position_subscriber2_;
    rclcpp::Subscription<VehicleLocalPosition>::SharedPtr local_position_subscriber3_;
    rclcpp::Subscription<VehicleLocalPosition>::SharedPtr local_position_subscriber4_;
    rclcpp::Subscription<VehicleLocalPosition>::SharedPtr local_position_subscriber5_;

    std::unordered_map<std::string, px4_msgs::msg::VehicleLocalPosition> current_positions_;

    State state_;
    uint64_t offboard_setpoint_counter_;

    void publish_offboard_control_mode();
    void send_vehicle_command(uint8_t system_id, uint16_t command, float param1 = 0.0, float param2 = 0.0);
    void publish_vehicle_command_all(uint16_t command, float param1 = 0.0, float param2 = 0.0);
    void local_position_callback(const px4_msgs::msg::VehicleLocalPosition::SharedPtr msg, const std::string &drone_id);
    void send_position_setpoint(uint8_t id, float x, float y, float z, float yaw);
};

void OffboardControl::arm()
{
    // Passa param2 = 21960.0f para forçar armamento caso haja restrições secundárias de pré-voo
    publish_vehicle_command_all(VehicleCommand::VEHICLE_CMD_COMPONENT_ARM_DISARM, 1.0f, 21960.0f);
    RCLCPP_INFO(this->get_logger(), "Comando de armar enviado a todos os drones.");
}

void OffboardControl::disarm()
{
    publish_vehicle_command_all(VehicleCommand::VEHICLE_CMD_COMPONENT_ARM_DISARM, 0.0f);
    RCLCPP_INFO(this->get_logger(), "Comando de desarme enviado a todos os drones.");
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
    offboard_control_mode_publisher4_->publish(msg);
    offboard_control_mode_publisher5_->publish(msg);
}

void OffboardControl::send_position_setpoint(uint8_t id, float x, float y, float z, float yaw)
{
    TrajectorySetpoint msg{};
    msg.position = {x, y, z};
    msg.yaw = yaw;
    msg.timestamp = this->get_clock()->now().nanoseconds() / 1000;

    switch (id)
    {
    case 1:
        trajectory_setpoint_publisher_->publish(msg);
        break;
    case 2:
        trajectory_setpoint_publisher2_->publish(msg);
        break;
    case 3:
        trajectory_setpoint_publisher3_->publish(msg);
        break;
    case 4:
        trajectory_setpoint_publisher4_->publish(msg);
        break;
    case 5:
        trajectory_setpoint_publisher5_->publish(msg);
        break;
    default:
        break;
    }
}

void OffboardControl::send_vehicle_command(uint8_t system_id, uint16_t command, float param1, float param2)
{
    VehicleCommand msg{};
    msg.param1 = param1;
    msg.param2 = param2;
    msg.command = command;
    msg.target_system = system_id; // Ajustado dinamicamente por drone
    msg.target_component = 1;
    msg.source_system = 1;
    msg.source_component = 1;
    msg.from_external = true;
    msg.timestamp = this->get_clock()->now().nanoseconds() / 1000;

    switch (system_id) {
    case 1:
        vehicle_command_publisher_->publish(msg);
        break;
    case 2:
        vehicle_command_publisher2_->publish(msg);
        break;
    case 3:
        vehicle_command_publisher3_->publish(msg);
        break;
    case 4:
        vehicle_command_publisher4_->publish(msg);
        break;
    case 5:
        vehicle_command_publisher5_->publish(msg);
        break;
    default:
        break;
    }
}

void OffboardControl::publish_vehicle_command_all(uint16_t command, float param1, float param2)
{
    for (uint8_t i = 1; i <= 5; ++i) {
        send_vehicle_command(i, command, param1, param2);
    }
}

void OffboardControl::local_position_callback(
    const px4_msgs::msg::VehicleLocalPosition::SharedPtr msg, 
    const std::string &drone_id) 
{
    current_positions_[drone_id] = *msg;

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

    float distance = std::sqrt(dx * dx + dy * dy + dz * dz);

    RCLCPP_INFO_THROTTLE(
        this->get_logger(), *this->get_clock(), 2000,
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