#!/usr/bin/env python3

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, Command, PathJoinSubstitution, TextSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch.substitutions import PythonExpression


def generate_launch_description():
    # Declare launch arguments
    vehicle_name_arg = DeclareLaunchArgument(
        'vehicle',
        default_value='lauv-simulator-1',
        description='Name of the vehicle to connect to via IMC'
    )
    
    frequency_arg = DeclareLaunchArgument(
        'frequency',
        default_value='10.0',
        description='Node update frequency in Hz'
    )
    
    use_sim_time_arg = DeclareLaunchArgument(
        'use_sim_time',
        default_value='true',
        description='Use simulation time'
    )
    
    origin_arg = DeclareLaunchArgument(
        'origin',
        default_value='[ 0.0, 0.0, 0.0 ]',
        description='Origin for the vehicle coordinate frame (comma-separated: x,y,z)'
    )
    
    rviz_config_arg = DeclareLaunchArgument(
        'rviz_config',
        default_value='lauv_rviz2.rviz',
        description='RViz configuration file name'
    )
    
    # Create namespace by converting hyphens to underscores
    vehicle_namespace = PythonExpression([
        "'", LaunchConfiguration('vehicle'), "'", ".replace('-', '_')"
    ])
    
    # Get package paths
    pkg_share = FindPackageShare('lauv')
    urdf_file = PathJoinSubstitution([pkg_share, 'urdf', 'lauv_ros2.xacro'])
    rviz_config_file = PathJoinSubstitution([pkg_share, 'rviz', LaunchConfiguration('rviz_config')])
    
    # Robot state publisher node
    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        namespace=vehicle_namespace,
        parameters=[{
            'robot_description': Command([
                'xacro ', urdf_file,
                ' namespace:=', vehicle_namespace
            ]),
            'use_sim_time': LaunchConfiguration('use_sim_time'),
            'publish_frequency': LaunchConfiguration('frequency')
        }],
        output='screen'
    )
    
    # Vehicle updater node
    update_vehicle_node = Node(
        package='lauv',
        executable='update_vehicle.py',
        name='vehicle_updater',
        parameters=[{
            'vehicle': LaunchConfiguration('vehicle'),
            'frequency': LaunchConfiguration('frequency'),
            'use_sim_time': LaunchConfiguration('use_sim_time'),
            'origin': LaunchConfiguration('origin')
        }],
        output='screen'
    )
    
    # RViz2 for visualization
    rviz2 = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        arguments=['-d', rviz_config_file],
        parameters=[{
            'use_sim_time': LaunchConfiguration('use_sim_time')
        }],
        output='screen'
    )

    return LaunchDescription([
        vehicle_name_arg,
        frequency_arg,
        use_sim_time_arg,
        origin_arg,
        rviz_config_arg,
        robot_state_publisher,
        update_vehicle_node,
        rviz2
    ])