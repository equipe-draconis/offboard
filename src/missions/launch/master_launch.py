from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
from launch.actions import ExecuteProcess
import os

def generate_launch_description():
    ld = LaunchDescription()



    

    offboard_master = Node(
        package='swarm_drone',
        executable='offboard_master',
        output='screen',
        shell=True,
    )

    

    ld.add_action(offboard_master)

    # ld.add_action(offboard5)

    # ld.add_action(bridge_node)

    return ld