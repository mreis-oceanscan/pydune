#!/usr/bin/env python3

import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, SetEnvironmentVariable
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    """
    Generate a complete launch description for the LAUV vehicle system.
    
    This launch file starts:
    - update_vehicle node (IMC bridge)
    - robot_state_publisher (URDF processing)
    - rviz2 (visualization)
    """
    
    # Declare launch arguments
    vehicle_name_arg = DeclareLaunchArgument(
        'vehicle_name',
        default_value='lauv-simulator-1',
        description='Name of the vehicle to connect to'
    )
    
    frequency_arg = DeclareLaunchArgument(
        'frequency',
        default_value='10.0',
        description='Update frequency in Hz'
    )
    
    origin_arg = DeclareLaunchArgument(
        'origin',
        default_value='[0.0, 0.0, 0.0]',
        description='Origin coordinates for the vehicle [x, y, z]'
    )
    
    use_rviz_arg = DeclareLaunchArgument(
        'use_rviz',
        default_value='true',
        description='Whether to start RViz visualization'
    )
    
    # Get package directory
    pkg_dir = get_package_share_directory('lauv')
    
    # Set up paths
    urdf_file = os.path.join(pkg_dir, 'robots', 'default.xacro')
    rviz_config_file = os.path.join(pkg_dir, 'rviz', 'lauv_rviz2.rviz')
    
    # Robot description parameter
    robot_description_content = PathJoinSubstitution([
        FindPackageShare('lauv'),
        'robots',
        'default.xacro'
    ])
    
    # Update vehicle node
    update_vehicle_node = Node(
        package='lauv',
        executable='update_vehicle.py',
        name='update_vehicle',
        output='screen',
        parameters=[{
            'vehicle': LaunchConfiguration('vehicle_name'),
            'frequency': LaunchConfiguration('frequency'),
            'origin': LaunchConfiguration('origin'),
        }],
        remappings=[
            # Remap topics based on vehicle name
            ('/joint_states', ['/', LaunchConfiguration('vehicle_name'), '/joint_states']),
        ]
    )
    
    # Robot state publisher node
    robot_state_publisher_node = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        output='screen',
        parameters=[{
            'robot_description': robot_description_content,
            'use_sim_time': False,
            'frame_prefix': [LaunchConfiguration('vehicle_name'), '/']
        }],
        remappings=[
            ('/joint_states', ['/', LaunchConfiguration('vehicle_name'), '/joint_states']),
        ]
    )
    
    # RViz node (conditional)
    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
        arguments=['-d', rviz_config_file],
        condition=LaunchConfiguration('use_rviz'),
        parameters=[{
            'use_sim_time': False
        }]
    )
    
    # Set environment variable for Python path
    python_path_env = SetEnvironmentVariable(
        'PYTHONPATH',
        [os.environ.get('PYTHONPATH', ''), ':', pkg_dir, '/scripts']
    )
    
    return LaunchDescription([
        # Environment setup
        python_path_env,
        
        # Launch arguments
        vehicle_name_arg,
        frequency_arg,
        origin_arg,
        use_rviz_arg,
        
        # Nodes
        update_vehicle_node,
        robot_state_publisher_node,
        rviz_node,
    ])