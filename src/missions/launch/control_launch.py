from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
from launch.actions import ExecuteProcess
import os

def generate_launch_description():
    ld = LaunchDescription()



    

    offboard1 = Node(
        package='swarm_drone',
        executable='offboard1',
        output='screen',
        shell=True,
    )

    offboard2 = Node(
        package='swarm_drone',
        executable='offboard2',
        output='screen',
        shell=True,
    )

    offboard3 = Node(
        package='swarm_drone',
        executable='offboard3',
        output='screen',
        shell=True,
    )
    offboard4 = Node(
        package='swarm_drone',
        executable='offboard4',
        output='screen',
        shell=True,
    )

    # offboard5 = Node(
    # package='swarm_drone',
    # executable='offboard5',
    # output='screen',
    # shell=True,
    # )



    # bridge_node = Node(
    #     package='ros_gz_bridge',
    #     executable='parameter_bridge',
    #     name='camera_bridge',
    #     parameters=[{'config_file': param_config}], # Note a chave 'config_file'
    #     output='screen',
    # )


    ld.add_action(offboard1)
    ld.add_action(offboard2)
    ld.add_action(offboard3)
    ld.add_action(offboard4)
    # ld.add_action(offboard5)

    # ld.add_action(bridge_node)

    return ld