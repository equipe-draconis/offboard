// offboard.h
#ifndef OFFBOARD_H // include guard
#define OFFBOARD_H
/**
 * @brief Offboard control example for single drone (px4_1)
 */

#include <px4_msgs/msg/offboard_control_mode.hpp>
#include <px4_msgs/msg/trajectory_setpoint.hpp>
#include <px4_msgs/msg/vehicle_command.hpp>
#include <px4_msgs/msg/vehicle_control_mode.hpp>
#include <px4_msgs/msg/vehicle_local_position.hpp>

// arm chck
#include <px4_msgs/msg/arming_check_request.hpp>
#include <px4_msgs/msg/arming_check_reply.hpp>

//battery
#include <px4_msgs/msg/battery_status.hpp>

//failsafes
#include <px4_msgs/msg/collision_constraints.hpp>
#include <px4_msgs/msg/failsafe_flags.hpp>
#include <px4_msgs/msg/home_position.hpp>

//manual controller
#include <px4_msgs/msg/manual_control_setpoint.hpp>

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
    FAILSAFE, 
    TMUX
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
        manual_controller_publisher_ = this->create_publisher<ManualControlSetpoint>("/px4_1/fmu/out/manual_control_setpoint", 10);
        home_position_publisher_ = this->create_publisher<HomePosition>("/px4_1/fmu/out/home_position", 10);
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
        // home_position_subscriber_ = this->create_subscription<HomePosition>(
        //     "/px4_1/fmu/out/home_position", qos,
        //     [this](const HomePosition::SharedPtr msg) {
        //         this->home_position_callback(msg);
        //     });
        //         // Subscritor da requisição enviada pelo PX4
        // arming_check_request_sub_ = this->create_subscription<ArmingCheckRequest>(
        //     "/fmu/out/arming_check_request", rclcpp::QoS(10).best_effort(),
        //     std::bind(&OffboardControl::armingCheckCallback, this, std::placeholders::_1));

     

        offboard_setpoint_counter_ = 0;
        timer_ = this->create_wall_timer(100ms, std::bind(&OffboardControl::timer_callback, this));
    }

    void arm();
    void disarm();
    bool has_reached_target(float target_x, float target_y, float target_z, float tolerance = 0.5f);

protected:
    rclcpp::TimerBase::SharedPtr timer_;

    rclcpp::Publisher<OffboardControlMode>::SharedPtr offboard_control_mode_publisher_;
    rclcpp::Publisher<TrajectorySetpoint>::SharedPtr trajectory_setpoint_publisher_;
    rclcpp::Publisher<ArmingCheckReply>::SharedPtr arming_check_reply_pub_;

    rclcpp::Publisher<ManualControlSetpoint>::SharedPtr manual_controller_publisher_;
    rclcpp::Publisher<VehicleCommand>::SharedPtr vehicle_command_publisher_;
    rclcpp::Publisher<HomePosition>::SharedPtr home_position_publisher_;
    
    rclcpp::Subscription<VehicleLocalPosition>::SharedPtr local_position_subscriber_;
    rclcpp::Subscription<ArmingCheckRequest>::SharedPtr arming_check_request_sub_;
    rclcpp::Subscription<HomePosition>::SharedPtr home_position_subscriber_;

    VehicleLocalPosition current_position_{};
    
    bool has_position_data_{false};

    State state_;
    uint64_t offboard_setpoint_counter_;

    void publish_offboard_control_mode();
    void publish_offboard_control_mode_velocity();
    void publish_vehicle_command(uint16_t command, float param1 = 0.0, float param2 = 0.0);
    void local_position_callback(const VehicleLocalPosition::SharedPtr msg);
    void send_velocity_setpoint(float vx, float vy, float vz, float yawspeed);
    void send_position_setpoint(float x, float y, float z, float yaw);
    void timer_callback();
    void set_home_position();
};

#endif /*OFFBOARD_H */