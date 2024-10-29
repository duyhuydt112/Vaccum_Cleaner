import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument, ExecuteProcess
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():
    # Tên package và đường dẫn đến file world
    package_name = 'my_bot'
    default_world_path = os.path.join(get_package_share_directory(package_name), 'worlds', 'testworld.world')

    # Khai báo biến world file có thể thay đổi được thông qua tham số launch
    world = LaunchConfiguration('world')

    # Xóa bộ nhớ đệm Gazebo trước khi khởi động
    clear_cache_cmd = ExecuteProcess(
        cmd=['rm', '-rf', os.path.expanduser('~/.gazebo/prefs'), os.path.expanduser('~/.gazebo/models')],
        output='screen'
    )

    # Include rsp.launch.py
    rsp = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([os.path.join(get_package_share_directory(package_name), 'launch', 'rsp.launch.py')]), 
        launch_arguments={'use_sim_time':'true'}.items()
    )

    # Include gazebo.launch.py và chỉ định file world
    gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([os.path.join(get_package_share_directory('gazebo_ros'), 'launch', 'gazebo.launch.py')]),
        launch_arguments={'world': world}.items()
    )

    # Node để spawn robot
    spawn_entity = Node(
        package='gazebo_ros', 
        executable='spawn_entity.py', 
        arguments=['-topic', 'robot_description', '-entity', 'my_bot'], 
        output='screen'
    )

    # Node cho diff drive controller
    diff_drive_spawner = Node(
        package="controller_manager",
        executable="spawner.py",
        arguments=["diff_cont"],
    )

    # Node cho joint state broadcaster
    joint_broad_spawner = Node(
        package="controller_manager",
        executable="spawner.py",
        arguments=["joint_broad"],
    )

    # Trả về LaunchDescription với các tham số và node đã cập nhật
    return LaunchDescription([
        DeclareLaunchArgument(
            'world',
            default_value=default_world_path,
            description='~/testpublicsher/src/my_bot/worlds/testworld.world'
        ),
        clear_cache_cmd,
        rsp,
        gazebo,
        spawn_entity,
        diff_drive_spawner,
        joint_broad_spawner
    ])
