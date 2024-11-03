import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node

def generate_launch_description():
    package_name = 'my_bot'
    rsp = IncludeLaunchDescription(PythonLaunchDescriptionSource([os.path.join(get_package_share_directory(package_name), 
    'launch','rsp.launch.py')]), launch_arguments={'use_sim_time': 'true', 'use_ros2_control': 'true'}.items())

    twist_mux_params = os.path.join(get_package_share_directory(package_name),'config','twist_mux.yaml')
    twist_mux = Node(
            package="twist_mux",
            executable="twist_mux",
            parameters=[twist_mux_params, {'use_sim_time': True}],
            # remappings=[('/cmd_vel_out','/diff_cont/cmd_vel_unstamped')]
            remappings=[('/cmd_vel_out','/diff_cont/cmd_vel_unstamped')]
        )

    gazebo_params_path = os.path.join(get_package_share_directory(package_name),'config','gazebo_params.yaml')

    gazebo = IncludeLaunchDescription(
            PythonLaunchDescriptionSource([os.path.join(get_package_share_directory('gazebo_ros'), 'launch', 'gazebo.launch.py')]), 
            launch_arguments={'extra_gazebo_args': '--ros-args --params-file ' + gazebo_params_path }.items()
            )
    spawn_entity = Node(package='gazebo_ros', executable='spawn_entity.py', arguments=['-topic', 'robot_description', '-entity', 'my_bot'], output='screen')
    diff_drive_spawner = Node(
        package="controller_manager",
        executable="spawner.py",
        arguments=["diff_cont"],
        # remappings=[('/odom','/tf')],
    )

    joint_broad_spawner = Node(
        package="controller_manager",
        executable="spawner.py",
        arguments=["joint_broad"],
    )



    # Launch them all!
    return LaunchDescription([
        rsp,
        gazebo,
        spawn_entity,
        twist_mux,
        diff_drive_spawner,
        joint_broad_spawner
    ])
       