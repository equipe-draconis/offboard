from launch import LaunchDescription
from launch.actions import ExecuteProcess
import os
from launch_ros.actions import Node 

from launch_ros.substitutions import FindPackageShare

PX4_PATH = "/home/marcos/projects/PX4-Autopilot"
PX4_BIN = f"{PX4_PATH}/build/px4_sitl_default/bin/px4"
gazebo_config_path="/home/marcos/projects/enxame_drone_lasc2026/src/swarm_drone/config/camera_config.yaml"
def generate_launch_description():

    ld = LaunchDescription()

    px4_1 = ExecuteProcess(
        cmd=[PX4_BIN, "-i", "1"],
        cwd=PX4_PATH,
        additional_env={
            # "PX4_GZ_WORLD": "bayland",
            "PX4_SYS_AUTOSTART": "4001",
            "PX4_SIM_MODEL": "gz_x500",
        },
        output='screen'
    )

    joy_cmd=Node (
        package="joy",
        executable= "joy_node",
        output = "screen"
    )

    # # Caminho equivalente a <let name="gazebo_config_path" ... />
    # gazebo_config_path = os.path.join(
    #     FindPackageShare('swarm_drone').find('swarm_drone'),
    #     'config',
    #     'camera_config.yaml',
    # )

    ros_gz_bridge_node = Node(
            package='ros_gz_bridge',
            executable='parameter_bridge',
            parameters=[{
                'config_file': '/home/marcos/projects/enxame_drone_lasc2026/src/swarm_drone/config/camera_config.yaml'
            }],
            output='screen',
        )

    # px4_2 = ExecuteProcess(
    #     cmd=[PX4_BIN, "-i", "2"],
    #     cwd=PX4_PATH,
    #     additional_env={
    #         "PX4_GZ_STANDALONE": "1",
    #         "PX4_SYS_AUTOSTART": "4001",
    #         "PX4_GZ_MODEL_POSE": "0,1",
    #         "PX4_SIM_MODEL": "gz_x500",
    #     },
    #     output='screen'
    # )

    # px4_3 = ExecuteProcess(
    #     cmd=[PX4_BIN, "-i", "3"],
    #     cwd=PX4_PATH,
    #     additional_env={
    #         "PX4_GZ_STANDALONE": "1",
    #         "PX4_SYS_AUTOSTART": "4001",
    #         "PX4_GZ_MODEL_POSE": "0,2",
    #         "PX4_SIM_MODEL": "gz_x500",
    #     },
    #     output='screen'
    # )

    # px4_4 = ExecuteProcess(
    #     cmd=[PX4_BIN, "-i", "4"],
    #     cwd=PX4_PATH,
    #     additional_env={
    #         "PX4_GZ_STANDALONE": "1",
    #         "PX4_SYS_AUTOSTART": "4001",
    #         "PX4_GZ_MODEL_POSE": "0,3",
    #         "PX4_SIM_MODEL": "gz_x500",
    #     },
    #     output='screen'
    # )

    # px4_5 = ExecuteProcess(
    #     cmd=[PX4_BIN, "-i", "5"],
    #     cwd=PX4_PATH,
    #     additional_env={
    #         "PX4_GZ_STANDALONE": "1",
    #         "PX4_SYS_AUTOSTART": "4001",
    #         "PX4_GZ_MODEL_POSE": "0,4",
    #         "PX4_SIM_MODEL": "gz_x500",
    #     },
    #     output='screen'
    # )

    ld.add_action(px4_1)
    ld.add_action(ros_gz_bridge_node)
    # ld.add_action(px4_3)
    # ld.add_action(px4_4)
    # ld.add_action(px4_5)

    return ld