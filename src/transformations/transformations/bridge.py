#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, Validity, History, Length

from geometry_msgs.msg import Twist, TransformStamped
from px4_msgs.msg import OffboardControlMode, TrajectorySetpoint, VehicleCommand, VehicleOdometry
from tf2_ros import TransformBroadcaster

class Nav2Px4Bridge(Node):

    def __init__(self):
        super().__init__('nav2_px4_bridge')

        # Configuração de QoS para comunicação com o microXRCE-DDS do PX4
        qos_profile = QoSProfile(
            history=History.KEEP_LAST,
            depth=1,
            reliability=Validity.RELIABLE,
            durability=Validity.VOLATILE
        )

        # ─── INSCRIÇÕES (SUBSCRIBERS) ───
        # Escuta os comandos de velocidade gerados pelo Nav2
        self.cmd_vel_sub = self.create_subscription(Twist, '/cmd_vel', self.cmd_vel_callback, 10)
        # Escuta a odometria nativa do PX4 para gerar o TF do Nav2
        self.px4_odom_sub = self.create_subscription(VehicleOdometry, '/fmu/out/vehicle_odometry', self.odom_callback, qos_profile)

        # ─── PUBLICAÇÕES (PUBLISHERS) ───
        self.offboard_mode_pub = self.create_publisher(OffboardControlMode, '/fmu/in/offboard_control_mode', qos_profile)
        self.trajectory_setpoint_pub = self.create_publisher(TrajectorySetpoint, '/fmu/in/trajectory_setpoint', qos_profile)
        self.vehicle_command_pub = self.create_publisher(VehicleCommand, '/fmu/in/vehicle_command', qos_profile)
        
        # Broadcaster de Transformações (TF)
        self.tf_broadcaster = TransformBroadcaster(self)

        # ─── VARIÁVEIS INTERNAS ───
        self.nav2_twist = Twist()
        self.offboard_setpoint_counter = 0

        # Timer para enviar o heartbeat do modo Offboard (O PX4 exige pelo menos 10Hz)
        self.timer = self.create_timer(0.1, self.timer_callback)

    def cmd_vel_callback(self, msg):
        """ Salva o comando de velocidade recebido do Nav2 """
        self.nav2_twist = msg

    def odom_callback(self, msg):
        """ Recebe a odometria do PX4 e publica o frame que o Nav2 precisa """
        t = TransformStamped()
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = 'odom'
        t.child_frame_id = 'base_link'

        # PX4 usa padrão NED (North-East-Down), convertemos para ENU (East-North-Up) do ROS
        t.transform.translation.x = msg.position[1]   # East
        t.transform.translation.y = msg.position[0]   # North
        t.transform.translation.z = -msg.position[2]  # Up (Invertido)

        # Orientação (Quatérnio)
        t.transform.rotation.x = msg.q[1]
        t.transform.rotation.y = msg.q[2]
        t.transform.rotation.z = msg.q[3]
        t.transform.rotation.w = msg.q[0]

        self.tf_broadcaster.sendTransform(t)

    def timer_callback(self):
        """ Ciclo principal de controle Offboard """
        # O PX4 precisa receber alguns comandos antes de aceitar entrar em modo Offboard de fato
        if self.offboard_setpoint_counter < 10:
            self.offboard_setpoint_counter += 1
        elif self.offboard_setpoint_counter == 10:
            # Ativa o modo Offboard e Arma os motores de forma automática
            self.publish_vehicle_command(VehicleCommand.VEHICLE_CMD_DO_SET_MODE, 1.0, 6.0)
            self.publish_vehicle_command(VehicleCommand.VEHICLE_CMD_COMPONENT_ARM_DISARM, 1.0)
            self.offboard_setpoint_counter += 1

        # 1. Publica a permissão de controle Offboard
        offboard_msg = OffboardControlMode()
        offboard_msg.timestamp = int(self.get_clock().now().nanoseconds / 1000)
        offboard_msg.position = False
        offboard_msg.velocity = True  # Avisa que estamos enviando comandos de velocidade
        offboard_msg.acceleration = False
        offboard_msg.attitude = False
        offboard_msg.body_rate = False
        self.offboard_mode_pub.publish(offboard_msg)

        # 2. Converte e envia as velocidades do Nav2 para o formato do PX4 (uORB)
        setpoint_msg = TrajectorySetpoint()
        setpoint_msg.timestamp = int(self.get_clock().now().nanoseconds / 1000)
        
        # Mapeamento de velocidade ENU (ROS) para NED (PX4)
        setpoint_msg.velocity[0] = self.nav2_twist.linear.y   # North
        setpoint_msg.velocity[1] = self.nav2_twist.linear.x   # East
        setpoint_msg.velocity[2] = -self.nav2_twist.linear.z  # Down
        setpoint_msg.yawspeed = -self.nav2_twist.angular.z    # Inversão de rotação se necessário

        self.trajectory_setpoint_pub.publish(setpoint_msg)

    def publish_vehicle_command(self, command, param1=0.0, param2=0.0):
        """ Envia comandos de sistema (Armar/Mudar Modo) para a FMU """
        msg = VehicleCommand()
        msg.timestamp = int(self.get_clock().now().nanoseconds / 1000)
        msg.command = command
        msg.param1 = param1
        msg.param2 = param2
        msg.target_system = 1
        msg.target_component = 1
        msg.source_system = 1
        msg.source_component = 1
        msg.from_external = True
        self.vehicle_command_pub.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    bridge = Nav2Px4Bridge()
    rclpy.spin(bridge)
    bridge.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()