#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.qos import (
    QoSProfile,
    ReliabilityPolicy,
    HistoryPolicy,
    DurabilityPolicy,
)

from px4_msgs.msg import VehicleLocalPosition, VehicleStatus


class Coletor(Node):
    """Nó que coleta o estado do veículo PX4 via micro XRCE-DDS."""

    def __init__(self) -> None:
        super().__init__('coletor')

        # QoS compatível com os tópicos /fmu/out/* do PX4
        qos_profile = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE,
            history=HistoryPolicy.KEEP_LAST,
            depth=1,
        )

        # Últimas mensagens recebidas (None até chegar a primeira)
        self.vehicle_local_position = None
        self.vehicle_status = None

        # Subscribers
        self.vehicle_local_position_subscriber = self.create_subscription(
            VehicleLocalPosition,
            '/fmu/out/vehicle_local_position',
            self.vehicle_local_position_callback,
            qos_profile,
        )
        self.vehicle_status_subscriber = self.create_subscription(
            VehicleStatus,
            '/fmu/out/vehicle_status',
            self.vehicle_status_callback,
            qos_profile,
        )

        self.get_logger().info('Nó coletor iniciado.')

    def vehicle_local_position_callback(self, msg: VehicleLocalPosition) -> None:
        """Callback do tópico vehicle_local_position."""
        self.vehicle_local_position = msg

    def vehicle_status_callback(self, msg: VehicleStatus) -> None:
        """Callback do tópico vehicle_status."""
        self.vehicle_status = msg


def main(args=None) -> None:
    rclpy.init(args=args)
    node = Coletor()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()