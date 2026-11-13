import os
from launch import LaunchDescription
from launch.actions import ExecuteProcess

def generate_launch_description():
    # Caminho até a raiz do diretório PX4-Autopilot (onde fica o Makefile)
    PX4_PATH = os.path.expanduser('~/projects/PX4-Autopilot') 

    # Executa o comando 'make px4_sitl gz_x500' de dentro da pasta correta
    px4_1 = ExecuteProcess(
        cmd=['make', 'px4_sitl', 'gz_x500'],
        cwd=PX4_PATH,

        output='screen'
    )

    return LaunchDescription([
        px4_1
    ])