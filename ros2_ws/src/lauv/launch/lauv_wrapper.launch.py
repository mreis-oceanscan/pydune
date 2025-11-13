import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.substitutions import LaunchConfiguration, Command, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def create_vehicle_nodes(context, *args, **kwargs):
    """Dynamically create nodes based on vehicles parameter"""
    
    # Get launch configuration values
    vehicles_str = LaunchConfiguration('vehicles').perform(context)
    frequency = LaunchConfiguration('frequency').perform(context)
    use_sim_time = LaunchConfiguration('use_sim_time').perform(context)
    
    # Parse vehicles list - expecting format like: ["lauv-simulator-1", "lauv-simulator-2"]
    try:
        # Remove brackets and quotes, split by comma
        vehicles_clean = vehicles_str.strip('[]').replace('"', '').replace("'", '')
        if vehicles_clean.strip():
            vehicles = [v.strip() for v in vehicles_clean.split(',')]
        else:
            vehicles = ['lauv-simulator-1']  # Default
    except Exception as e:
        print(f"Error parsing vehicles list: {e}")
        vehicles = ['lauv-simulator-1']  # Fallback
    
    # Find package directory
    pkg_share = FindPackageShare('lauv')
    urdf_file = PathJoinSubstitution([pkg_share, 'urdf', 'lauv_ros2.xacro'])
    
    # Create nodes for each vehicle
    nodes = []
    
    for i, vehicle_name in enumerate(vehicles):
        namespace = vehicle_name.replace('-', '_')  # Convert to ROS2-friendly namespace
        color = 'blue' if i % 2 == 0 else 'red'  # Alternate colors for vehicles
        
        # Vehicle updater node for this vehicle
        update_vehicle_node = Node(
            package='lauv',
            executable='update_vehicle.py',
            name=f'vehicle_updater_{i+1}',
            parameters=[{
                'frequency': float(frequency),
                'vehicle': vehicle_name,
                'use_sim_time': use_sim_time == 'true'
            }],
            output='screen'
        )
        
        # Robot state publisher for this vehicle
        robot_state_publisher = Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name=f'robot_state_publisher_{i+1}',
            namespace=namespace,
            parameters=[{
                'robot_description': Command([
                    'xacro ', urdf_file,
                    f' namespace:={namespace}',
                    f' color_scheme:={color}'
                ]),
                'use_sim_time': use_sim_time == 'true',
                'publish_frequency': float(frequency)
            }],
            output='screen'
        )

        nodes.extend([update_vehicle_node, robot_state_publisher])

    return nodes


def generate_launch_description():
    # Declare launch arguments
    vehicles_arg = DeclareLaunchArgument(
        'vehicles',
        default_value='["lauv-simulator-1", "lauv-simulator-2"]',
        description='List of vehicle names to launch (as a string representation of a list)'
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
    
    rviz_config_arg = DeclareLaunchArgument(
        'rviz_config',
        default_value='multi_vehicle.rviz',
        description='RViz configuration file name (lauv_rviz2.rviz or multi_vehicle.rviz)'
    )

    # RViz2 for visualization
    rviz_config_file = PathJoinSubstitution([
        FindPackageShare('lauv'), 
        'rviz', 
        LaunchConfiguration('rviz_config')
    ])
    
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

    # Dynamically create vehicle nodes
    vehicle_nodes = OpaqueFunction(function=create_vehicle_nodes)

    return LaunchDescription([
        vehicles_arg,
        frequency_arg,
        use_sim_time_arg,
        rviz_config_arg,
        vehicle_nodes,
        rviz2
    ])