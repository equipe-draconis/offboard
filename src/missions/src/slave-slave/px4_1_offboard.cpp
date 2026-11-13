
#include <px4_msgs/msg/offboard_control_mode.hpp>
#include <px4_msgs/msg/vehicle_local_position.hpp>
#include <px4_msgs/msg/trajectory_setpoint.hpp>
#include <px4_msgs/msg/vehicle_command.hpp>
#include <px4_msgs/msg/vehicle_control_mode.hpp>
#include <rclcpp/rclcpp.hpp>
#include <stdint.h>

#include <chrono>
#include <iostream>

using namespace std::chrono;
using namespace std::chrono_literals;
using namespace px4_msgs::msg;

class OffboardControl : public rclcpp::Node
{
public:
	OffboardControl() : Node("offboard_control")
	{

		offboard_control_mode_publisher_ = this->create_publisher<OffboardControlMode>("/px4_1/fmu/in/offboard_control_mode", 10);

		trajectory_setpoint_publisher_ = this->create_publisher<TrajectorySetpoint>("/px4_1/fmu/in/trajectory_setpoint", 10);

		vehicle_command_publisher_ = this->create_publisher<VehicleCommand>("/px4_1/fmu/in/vehicle_command", 10);

		   // subscriber for others UAVs
        subscription_px4_1 = this->create_subscription<VehicleLocalPosition>(
         "/px4_1/fmu/out/vehicle_local_position", 10, std::bind(& OffboardControl::position_callback_1	, this, _1));

        // subscriber for others UAVs
        subscription_px4_2 = this->create_subscription<VehicleLocalPosition>(
         "/px4_2/fmu/out/vehicle_local_position", 10, std::bind(& OffboardControl::position_callback_2, this, _1));

        subscription_px4_3 = this->create_subscription<VehicleLocalPosition>(
         "/px4_3/fmu/out/vehicle_local_position", 10, std::bind(& OffboardControl::position_callback_3, this, _1));

        subscription_px4_4 = this->create_subscription<VehicleLocalPosition>(
        "/px4_4/fmu/out/vehicle_local_position", 10, std::bind(& OffboardControl::position_callback_4, this, _1));

		offboard_setpoint_counter_ = 0;
		auto timer_callback = [this]() -> void {
			// Publica setpoints ANTES e DURANTE o offboard (obrigatório para o PX4 aceitar o modo)
			publish_offboard_control_mode();
			publish_trajectory_setpoint();

			// Tenta entrar em Offboard após 10 ciclos (1 segundo)
			// mas continua tentando se falhar até o ciclo 100
		if (offboard_setpoint_counter_ >= 10) {
			// RCLCPP_INFO(this->get_logger(), "FORÇANDO OFFBOARD + ARM");
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
    rclcpp::Subscription<VehicleLocalPosition>::SharedPtr subscription_px4_1;
    rclcpp::Subscription<VehicleLocalPosition>::SharedPtr subscription_px4_2;
    rclcpp::Subscription<VehicleLocalPosition>::SharedPtr subscription_px4_3;
    rclcpp::Subscription<VehicleLocalPosition>::SharedPtr subscription_px4_4;

	std::atomic<uint64_t> timestamp_;   //!< common synced timestamped

	uint64_t offboard_setpoint_counter_;   //!< counter for the number of setpoints sent

    VehicleLocalPosition::SharedPtr pos_px4_2;
    VehicleLocalPosition::SharedPtr pos_px4_3;
    VehicleLocalPosition::SharedPtr pos_px4_4;
	 void position_callback_1(const VehicleLocalPosition::SharedPtr msg);
    void position_callback_2(const VehicleLocalPosition::SharedPtr msg);
    void position_callback_3(const VehicleLocalPosition::SharedPtr msg);
    void position_callback_4(const VehicleLocalPosition::SharedPtr msg);
	void publish_offboard_control_mode();
	void publish_trajectory_setpoint();
	void publish_vehicle_command(uint16_t command, float param1 = 0.0, float param2 = 0.0);
    void calculated_new_postion(vehicleLocalPosition::SharedPtr pos_px4_2, VehicleLocalPosition::SharedPtr pos_px4_3, VehicleLocalPosition::SharedPtr pos_px4_4);


   
};

/**
 * @brief Send a command to Arm the vehicle
 */
void OffboardControl::arm()
{
	publish_vehicle_command(VehicleCommand::VEHICLE_CMD_COMPONENT_ARM_DISARM, 1.0);

	RCLCPP_INFO(this->get_logger(), "Arm command send");
}

/**
 * @brief Send a command to Disarm the vehicle
 */
void OffboardControl::disarm()
{
	publish_vehicle_command(VehicleCommand::VEHICLE_CMD_COMPONENT_ARM_DISARM, 0.0);

	RCLCPP_INFO(this->get_logger(), "Disarm command send");
}

/**
 * @brief Publish the offboard control mode.
 *        For this example, only position and altitude controls are active.
 */
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

/**
 * @brief Publish a trajectory setpoint
 *        For this example, it sends a trajectory setpoint to make the
 *        vehicle hover at 5 meters with a yaw angle of 180 degrees.
 */
void OffboardControl::publish_trajectory_setpoint()
{
	TrajectorySetpoint msg{};
	msg.position = {0.0, 0.0, -5.0};
	msg.yaw = -3.14; // [-PI:PI]
	msg.timestamp = this->get_clock()->now().nanoseconds() / 1000;
	trajectory_setpoint_publisher_->publish(msg);
}

/**
 * @brief Publish vehicle commands
 * @param command   Command code (matches VehicleCommand and MAVLink MAV_CMD codes)
 * @param param1    Command parameter 1
 * @param param2    Command parameter 2
 */
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

/**
 * @brief Receive position updates from PX4_2
 * @param msg   The position message
 */
void OffboardControl::position_callback_1(const VehicleLocalPosition::SharedPtr msg)
{
    RCLCPP_INFO(this->get_logger(), "Received position from PX4_1: lat=%f, lon=%f, alt=%f", msg->lat, msg->lon, msg->alt);
    pos_px4_1 = {msg->lat, msg->lon, msg->alt};
}

/**
 * @brief Receive position updates from PX4_2
 * @param msg   The position message
 */
void OffboardControl::position_callback_2(const VehicleLocalPosition::SharedPtr msg)
{
    RCLCPP_INFO(this->get_logger(), "Received position from PX4_2: lat=%f, lon=%f, alt=%f", msg->lat, msg->lon, msg->alt);
    pos_px4_2 = {msg->lat, msg->lon, msg->alt};
}

/**
 * @brief Receive position updates from PX4_3
 * @param msg   The position message
 */

void OffboardControl::position_callback_3(const VehicleLocalPosition::SharedPtr msg)
{
    RCLCPP_INFO(this->get_logger(), "Received position from PX4_3: lat=%f, lon=%f, alt=%f", msg->lat, msg->lon, msg->alt);
    pos_px4_3 = {msg->lat, msg->lon, msg->alt};
}

/**
 * @brief Receive position updates from PX4_4
 * @param msg   The position message
 */

void OffboardControl::position_callback_4(const VehicleLocalPosition::SharedPtr msg)
{
    RCLCPP_INFO(this->get_logger(), "Received position from PX4_4: lat=%f, lon=%f, alt=%f", msg->lat, msg->lon, msg->alt);
    pos_px4_4 = {msg->lat, msg->lon, msg->alt};
}

/**
 * @brief Calculated new position based on the positions of PX4_2, PX4_3, and PX4_4
 *        For this example, it calculates the average position of the three drones.
 *        This is a placeholder for more complex swarm behavior algorithms.
 *       For this we define minimum distance between drones and if the distance is less than the minimum distance, we will change the position of the drone to avoid collision, What triggers a chain reaction when drone positions change
 * @param pos_px4_2   Position message from PX4_2
 * @param pos_px4_3   Position message from PX4_3
 * @param pos_px4_4   Position message from PX4_4
 */
void OffboardControl::calculated_new_position(VehicleLocalPosition::SharedPtr pos_px4_2, VehicleLocalPosition::SharedPtr pos_px4_3, VehicleLocalPosition::SharedPtr pos_px4_4)
{
    
}