#!/usr/bin/env python3

import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, Command
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    """
    Simple launch file for LAUV vehicle system.
    Launches: update_vehicle, robot_state_publisher, and rviz2
    """
    
    # Get package directory
    pkg_dir = get_package_share_directory('lauv')
    
    # Paths
    urdf_file = os.path.join(pkg_dir, 'robots', 'lauv_ros2.xacro')
    rviz_config = os.path.join(pkg_dir, 'rviz', 'lauv_rviz2.rviz')
    
    # Process URDF
    robot_description = Command(['xacro ', urdf_file])
    
    return LaunchDescription([
        # Launch arguments
        DeclareLaunchArgument(
            'vehicle_name',
            default_value='lauv-simulator-1',
            description='Vehicle name'
        ),
        
        # Update vehicle node - the main IMC bridge
        Node(
            package='lauv',
            executable='update_vehicle.py',
            name='update_vehicle',
            output='screen',
            parameters=[{
                'vehicle': LaunchConfiguration('vehicle_name'),
                'frequency': 10.0,
                'origin': [0.0, 0.0, 0.0]
            }]
        ),
        
        # Robot state publisher - handles URDF and transforms
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            output='screen',
            parameters=[{
                'robot_description': robot_description,
                'use_sim_time': False
            }]
        ),
        
        # RViz for visualization
        Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            output='screen',
            arguments=['-d', rviz_config]
        ),
    ])