# Vaccum_Cleaner
+ source install/setup.bash
+ ros2 run teleop_twist_keyboard teleop_twist_keyboard 
+ LC_NUMERIC="en_US.UTF-8"; ros2 run rviz2 rviz2
+ ros2 launch my_bot launch_sim.launch.py world:=~/testpublicsher/src/my_bot/worlds/testworld.world
+ ros2 launch slam_toolbox online_async_launch.py params_file:=./src/my_bot/config/mapper_params_online_async.yaml use_sim_time:=true
+ ros2 launch nav2_bringup navigation_launch.py use_sim_time:=true params_file:=./src/my_bot/config/nav2_params.yaml 
+ https://robotics.snowcron.com/robotics_ros2/robotics_ros2.htm
https://github.com/ros-navigation/navigation2/issues/4027
+ ros2 run twist_mux twist_mux --ros-args --params-file ./src/my_bot/config/twist_mux.yaml -r cmd_vel_out:=diff_cont/cmd_vel_unstamped
