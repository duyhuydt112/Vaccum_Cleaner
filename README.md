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
+ ros2 run tf2_tools view_frames.py
+ ros2 run teleop_twist_keyboard teleop_twist_keyboard --ros-args -r /cmd_vel:=/key_board
+ errror shchedual: https://docs.google.com/document/d/1yaQNlgrnH9eBzvAaWgLmfuhKEVl-1CULxKFdlTZdlWg/edit?usp=sharing
+ Mastering ROS for Robotics Programming, Third edition: Best practices and troubleshooting solutions when working with ROS , Third Edition
https://emanual.robotis.com/docs/en/platform/turtlebot3/slam/#run-slam-node
https://emanual.robotis.com/docs/en/platform/turtlebot3/slam/#tuning-guide
