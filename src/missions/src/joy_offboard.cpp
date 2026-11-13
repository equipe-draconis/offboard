#include "offboard.h"
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joy.hpp"
#include "std_msgs/msg/float64.hpp"

using namespace sensor_msgs::msg;

// Herda diretamente de OffboardControl (que já é um rclcpp::Node)
class ManualOffboardControlNode : public OffboardControl
{
public:
    ManualOffboardControlNode() : OffboardControl()
    {
        subscription_joy = this->create_subscription<sensor_msgs::msg::Joy>(
            "/joy", 10, std::bind(&ManualOffboardControlNode::joy_callback, this, std::placeholders::_1)
        );

        // Publishers dos motores/juntas do robô
        publisher_head_pitch = this->create_publisher<std_msgs::msg::Float64>("/head_pitch", 10);
        pub_r_shoulder_p    = this->create_publisher<std_msgs::msg::Float64>("/r_shoulder_p", 10);
        pub_r_shoulder_r    = this->create_publisher<std_msgs::msg::Float64>("/r_shoulder_r", 10);
        pub_l_shoulder_p    = this->create_publisher<std_msgs::msg::Float64>("/l_shoulder_p", 10);
        pub_l_shoulder_r    = this->create_publisher<std_msgs::msg::Float64>("/l_shoulder_r", 10);

        // Publishers das pernas/quadril
        pub_l_hip_roll_  = this->create_publisher<std_msgs::msg::Float64>("/l_hip_roll", 10);
        pub_r_hip_roll_  = this->create_publisher<std_msgs::msg::Float64>("/r_hip_roll", 10);
        pub_l_hip_pitch_ = this->create_publisher<std_msgs::msg::Float64>("/l_hip_pitch", 10);
        pub_r_hip_pitch_ = this->create_publisher<std_msgs::msg::Float64>("/r_hip_pitch", 10);
        pub_l_knee_      = this->create_publisher<std_msgs::msg::Float64>("/l_knee", 10);
        pub_r_knee_      = this->create_publisher<std_msgs::msg::Float64>("/r_knee", 10);
    }

private:
    void joy_callback(const Joy::SharedPtr msg);

    rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr subscription_joy;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr publisher_head_pitch;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr pub_r_shoulder_p;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr pub_r_shoulder_r;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr pub_l_shoulder_p;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr pub_l_shoulder_r;

    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr pub_l_hip_roll_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr pub_r_hip_roll_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr pub_l_hip_pitch_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr pub_r_hip_pitch_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr pub_l_knee_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr pub_r_knee_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ManualOffboardControlNode>());
    rclcpp::shutdown();
    return 0;
}

void ManualOffboardControlNode::joy_callback(const Joy::SharedPtr msg)
{   
    auto msg_head_pitch = std_msgs::msg::Float64();
    auto msg_r_shoulder_p = std_msgs::msg::Float64();
    auto msg_r_shoulder_r = std_msgs::msg::Float64();
    auto msg_l_shoulder_p = std_msgs::msg::Float64();
    auto msg_l_shoulder_r = std_msgs::msg::Float64();

    std_msgs::msg::Float64 l_hip_r, r_hip_r, l_hip_p, r_hip_p, l_knee, r_knee;

    float left_stick_y  = msg->axes[1];
    float right_stick_x = msg->axes[2];
    float right_stick_y = msg->axes[3];

    // Lógica do Joystick
    if (left_stick_y > 0.2f) {
        msg_head_pitch.data = 1;
    } else if (left_stick_y < -0.2f) {
        msg_head_pitch.data = -1;
    } else if (right_stick_y > 0.2f) {
        msg_r_shoulder_p.data = 2;
        msg_l_shoulder_p.data = 2;
    } else if (right_stick_y < -0.2f) {
        msg_r_shoulder_p.data = -2;
        msg_l_shoulder_p.data = -2;
    } else if (right_stick_x > 0.2f) {
        msg_r_shoulder_r.data = 3;
        msg_l_shoulder_r.data = 3;
    } else if (right_stick_x < -0.2f) {
        msg_r_shoulder_r.data = -3;
        msg_l_shoulder_r.data = -3;
    } else {
        msg_head_pitch.data = 0;
        msg_r_shoulder_p.data = 0;
        msg_r_shoulder_r.data = 0;
        msg_l_shoulder_p.data = 0;
        msg_l_shoulder_r.data = 0;
    }

    publisher_head_pitch->publish(msg_head_pitch);
    pub_r_shoulder_p->publish(msg_r_shoulder_p);
    pub_r_shoulder_r->publish(msg_r_shoulder_r);
    pub_l_shoulder_p->publish(msg_l_shoulder_p);
    pub_l_shoulder_r->publish(msg_l_shoulder_r);

    pub_l_hip_roll_->publish(l_hip_r);
    pub_r_hip_roll_->publish(r_hip_r);
    pub_l_hip_pitch_->publish(l_hip_p);
    pub_r_hip_pitch_->publish(r_hip_p);
    pub_l_knee_->publish(l_knee);
    pub_r_knee_->publish(r_knee);

    // Máquina de estados FSM envolvendo o switch
    switch (state_) {
        case State::INIT_OFFBOARD:
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

        case State::TMUX:
            // Estado neutro/customizado
            break;
    }
}