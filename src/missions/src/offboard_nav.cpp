#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <px4_msgs/msg/offboard_control_mode.hpp>
#include <px4_msgs/msg/trajectory_setpoint.hpp>
#include <px4_msgs/msg/vehicle_command.hpp>
#include <px4_msgs/msg/vehicle_odometry.hpp>
#include <tf2_ros/transform_broadcaster.h>

using namespace std::chrono_literals;
using namespace px4_msgs::msg;

class Nav2Px4Bridge : public rclcpp::Node
{
public:
    Nav2Px4Bridge() : Node("nav2_px4_bridge")
    {
        // Configuração de QoS compatível com o microXRCE-DDS do PX4
        rmw_qos_profile_t qos_profile = rmw_qos_profile_sensor_data;
        auto qos = rclcpp::QoS(rclcpp::QoSInitialization(qos_profile.history, 1), qos_profile);
        
        // ─── SUBSCRITORES (Utilizando lambdas para evitar bugs com placeholders) ───
        cmd_vel_sub_ = this->create_subscription<geometry_msgs::msg::Twist>(
            "/cmd_vel", 10, [this](const geometry_msgs::msg::Twist::SharedPtr msg) {
                cmd_vel_callback(msg);
            });

        px4_odom_sub_ = this->create_subscription<VehicleOdometry>(
            "/fmu/out/vehicle_odometry", qos, [this](const VehicleOdometry::SharedPtr msg) {
                odom_callback(msg);
            });

        // ─── PUBLICADORES ───
        offboard_control_mode_pub_ = this->create_publisher<OffboardControlMode>("/fmu/in/offboard_control_mode", 10);
        trajectory_setpoint_pub_ = this->create_publisher<TrajectorySetpoint>("/fmu/in/trajectory_setpoint", 10);
        vehicle_command_pub_ = this->create_publisher<VehicleCommand>("/fmu/in/vehicle_command", 10);

        tf_broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(*this);
        offboard_setpoint_counter_ = 0;

        // Timer principal de controlo a 10Hz (100ms) - (Duplicidade removida)
        timer_ = this->create_wall_timer(100ms, [this]() { timer_callback(); });
    }

private:
    void cmd_vel_callback(const geometry_msgs::msg::Twist::SharedPtr msg)
    {
        nav2_twist_ = *msg;
    }

    void odom_callback(const VehicleOdometry::SharedPtr msg)
    {
        geometry_msgs::msg::TransformStamped t;

        t.header.stamp = this->get_clock()->now();
        t.header.frame_id = "odom";
        t.child_frame_id = "base_link";

        // Conversão de coordenadas nativas do PX4 (NED) para o padrão do ROS 2 (ENU)
        t.transform.translation.x = msg->position[1];   // East
        t.transform.translation.y = msg->position[0];   // North
        t.transform.translation.z = -msg->position[2];  // Up (Invertido)

        // Passagem do Quaternión de orientação
        t.transform.rotation.x = msg->q[1];
        t.transform.rotation.y = msg->q[2];
        t.transform.rotation.z = msg->q[3];
        t.transform.rotation.w = msg->q[0];

        tf_broadcaster_->sendTransform(t);
    }

    void timer_callback()
    {
        // Envia os batimentos de segurança (heartbeat) exigidos pelo PX4 antes de armar
        publish_offboard_control_mode();
        publish_trajectory_setpoint();

        // Ativa o modo Offboard e Arma após 10 ciclos estáveis (1 segundo)
        if (offboard_setpoint_counter_ == 10) {
            RCLCPP_INFO(this->get_logger(), "FORÇANDO OFFBOARD + ARM NO DRONE px4_1 (C++)");
            publish_vehicle_command(VehicleCommand::VEHICLE_CMD_DO_SET_MODE, 1.0f, 6.0f);
            publish_vehicle_command(VehicleCommand::VEHICLE_CMD_COMPONENT_ARM_DISARM, 1.0f);
        }

        if (offboard_setpoint_counter_ < 11) {
            offboard_setpoint_counter_++;
        }
    }

    void publish_offboard_control_mode()
    {
        OffboardControlMode msg{};
        msg.timestamp = this->get_clock()->now().nanoseconds() / 1000;
        msg.position = false;
        msg.velocity = true; // Ativa a aceitação de setpoints de velocidade dinâmicos
        msg.acceleration = false;
        msg.attitude = false;
        msg.body_rate = false;
        offboard_control_mode_pub_->publish(msg);
    }

    void publish_trajectory_setpoint()
    {
        TrajectorySetpoint msg{};
        msg.timestamp = this->get_clock()->now().nanoseconds() / 1000;

        // Mapeamento das velocidades geométricas ENU (ROS) para NED (PX4)
        msg.velocity[0] = nav2_twist_.linear.y;    // North
        msg.velocity[1] = nav2_twist_.linear.x;    // East
        msg.velocity[2] = -nav2_twist_.linear.z;   // Down
        msg.yawspeed = -nav2_twist_.angular.z;     // Inversão angular se necessário

        trajectory_setpoint_pub_->publish(msg);
    }

    void publish_vehicle_command(uint16_t command, float param1, float param2 = 0.0f)
    {
        VehicleCommand msg{};
        msg.timestamp = this->get_clock()->now().nanoseconds() / 1000;
        msg.command = command; // Corrigido: adicionado ponto e vírgula
        msg.param1 = param1;
        msg.param2 = param2;
        msg.target_system = 0; // Mantido a zero conforme a tua configuração alvo
        msg.target_component = 1;
        msg.source_system = 1;
        msg.source_component = 1;
        msg.from_external = true;
        vehicle_command_pub_->publish(msg);
    }

    // Declaração dos ponteiros e subnós
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_sub_;
    rclcpp::Subscription<VehicleOdometry>::SharedPtr px4_odom_sub_;

    rclcpp::Publisher<OffboardControlMode>::SharedPtr offboard_control_mode_pub_;
    rclcpp::Publisher<TrajectorySetpoint>::SharedPtr trajectory_setpoint_pub_;
    rclcpp::Publisher<VehicleCommand>::SharedPtr vehicle_command_pub_;

    std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;

    geometry_msgs::msg::Twist nav2_twist_;
    uint64_t offboard_setpoint_counter_;
};

int main(int argc, char *argv[])
{
    std::cout << "A iniciar o nó bridge Nav2 para PX4 em C++..." << std::endl;
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Nav2Px4Bridge>());
    rclcpp::shutdown();
    return 0;
}