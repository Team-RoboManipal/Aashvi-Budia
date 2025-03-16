```markdown
# ROS 2 Documentation

## rclpy
**rclpy** is the ROS 2 (Robot Operating System) Python client library. It provides the Python bindings to the ROS 2 core, allowing developers to write ROS 2 nodes in Python. Service clients, publisher, subscriber nodes, logging, timers.

## rqt
**rqt** is a graphical interface for ROS 2.

## Node
Each node in ROS should be responsible for a single, modular purpose, e.g., controlling the wheel motors or publishing the sensor data from a laser range-finder. Each node can send and receive data from other nodes via topics, services, actions, or parameters.

```bash
ros2 node info /my_turtle
```
Returns a list of subscribers, publishers, services, and actions, i.e., the ROS graph connections that interact with that node.

### PARAMETER
A parameter of a node in ROS 2 is a configurable value associated with a node that allows you to customize its behavior without modifying the code.

To display the type and current value of a parameter, use the command:
```bash
ros2 param get <node_name> <parameter_name>
ros2 param set <node_name> <parameter_name> <value>
ros2 run <package_name> <executable_name> --ros-args --params-file <file_name>
```

### Background
```bash
ros2 launch turtlesim multisim.launch.py
```
Runs two turtlesims (nodes) with one terminal.

## Topic
Way to communicate between nodes. A node may publish data to any number of topics and simultaneously have subscriptions to any number of topics.

```bash
ros2 topic pub
```

## Services
Call-and-response model. Topics allow nodes to subscribe to data streams and get continual updates, services only provide data when they are specifically called by a client. There can be many clients using the same service but there can only be one server providing it.

```bash
ros2 interface show <type_name>
```
Shows the structure of the input argument of a service type.

Call async: run simultaneously whilst other tasks are running or sync: pauses entirely until receives response.

The Empty type means the service call sends no data when making a request and receives no data when receiving a response.

```bash
/clear
```

## Actions
Actions in ROS 2 are a communication mechanism used for long-running tasks that provide periodic feedback during execution and allow for preemption (cancellation). They are ideal for scenarios where a task may take some time to complete and you want intermediate updates or the ability to stop the task before it finishes.

### rqt_console
Typically, log messages show up in your terminal. With rqt_console, you can collect those messages over time, view them closely and in a more organized manner.

```bash
ros2 topic hz /turtle1/pose
```
Tells the amount of times the data is being published on pose.

### ros2 bag
**ros2 bag** is a command line tool for recording data published on topics in your system. It accumulates the data passed on any number of topics and saves it in a database.

```bash
ros2 bag record <topic_name>
```

An executable refers to a script or binary that can be invoked to start a node, a subscriber, a publisher, or perform any other functionality.

A package is like a folder for organizing ROS-related code and resources. An executable is a program or binary generated from that package, which can be run as a node in the ROS 2 system.

The install directory contains symlinks pointing back to the actual files in the source or build directory. Changes to the source files are automatically available in the install directory without rebuilding.

Sourcing is a command (`source`) that loads a specific setup script to make sure your terminal knows where ROS 2 and its tools are located. Without sourcing, the system won’t know where to find important things like ROS 2 libraries, tools, or dependencies.

## Workspace
Inside `src` is where the source code of ROS packages will be located. The build directory will be where intermediate files are stored. The install directory is where each package will be installed to. By default, each package will be installed into a separate subdirectory. The log directory contains various logging information about each colcon invocation.

The underlay is the base ROS 2 installation or workspace. It has already been built and includes all the core ROS 2 packages and any extra packages you’ve added.

The overlay is the workspace where you work on your custom packages. It "sits on top" of the underlay, meaning it uses everything in the underlay but lets you add or override packages with your custom code.

```bash
source install/setup.bash
```
Before you can use any of the installed executables or libraries, you will need to add them to your path and library paths. If you add or modify something in `~/.bashrc`, like environment variables for ROS 2, those changes don't apply to the current terminal session until you "source" it. Running `source ~/.bashrc` reloads the file, applying your changes without reopening the terminal.

### Colcon build
**colcon build** is a command used in ROS 2 to build the packages in your workspace. It compiles the source code, resolves dependencies, and sets up everything required for the ROS 2 packages to run.

```bash
colcon build --executor sequential
```

## Package
A package is an organizational unit for your ROS 2 code. If you want to be able to install your code or share it with others, then you'll need it organized in a package. With packages, you can release your ROS 2 work and allow others to build and use it easily. You cannot have nested packages.

```bash
ros2 pkg create --build-type ament_python my_robot_package --dependencies relpy
```
Putting packages in a workspace is especially valuable because you can build many packages at once by running `colcon build` in the workspace root. Otherwise, you would have to build each package individually.

```bash
colcon build --packages-select my_package
```

### In C++
- `<chrono>`: This header is part of the C++ standard library and is used for time-related operations, such as handling time intervals, measuring time, or implementing timeouts.
- `<functional>`: This header allows you to use standard functions, such as `std::function` (for creating function pointers or callback functions).
- `<memory>`: This header provides smart pointers like `std::shared_ptr`, which help manage memory automatically, avoiding manual memory management.
- `<string>`: This includes the C++ string library that provides the `std::string` class for working with strings.
- `"rclcpp/rclcpp.hpp"`: This is the main header file for ROS 2 in C++. It provides essential functionality for working with ROS 2 nodes, publishers, subscribers, and other ROS 2 functionalities.
- `"std_msgs/msg/string.hpp"`: This includes the definition of the `std_msgs::msg::String` message type. ROS 2 uses messages to pass data between nodes, and this particular message type is used to send strings.

- The `main()` function initializes the node and starts the event loop (using `relpy.spin()`) to keep the node running. Without this structure, the node would not be able to communicate via ROS topics, services, actions, etc.

### Simplifies Execution
- By defining the entry point in the `setup.py` file (via the `entry_points`), you tell ROS 2 where to find the executable that should be run when the user calls `ros2 run`.
- This enables ROS 2 to automatically run the code inside the `main()` function when you execute the node.

## Shebang
```python
#!/usr/bin/env python3
```
This line allows the script to be executed directly from the terminal if it has execute permissions.

```python
draw_circle=my_robot_controller.draw_circle:main'
```
The first part (`draw_circle`) is the name of the executable. The second part (`my_robot_controller.draw_circle:main`) specifies the module (`my_robot_controller.draw_circle`) and the `main()` function to run.

### echo
**echo** is used to view the messages being published on a topic.

### rosdep
**rosdep** is a command-line tool that can check and install dependencies for your ROS 2 workspace.

```bash
rosdep install --from-paths src --ignore-src -r -y
```
Run this in your workspace to install any missing dependencies that are listed in your packages. `rosdep` is not a package manager in its own right; it is a meta-package manager that uses its own knowledge of the system and the dependencies to find the appropriate package to install on a particular platform.

Before building a workspace, you need to ensure all dependencies (other packages or libraries) are installed. Dependencies are required for your code to compile and run properly. When cloning a repository or creating a new workspace, checking for missing dependencies is important to avoid build failures later. Declare dependencies in the `package.xml` file. The dependencies in the `package.xml` file are generally referred to as `rosdep` keys.

Sourcing the `local_setup` of the overlay will only add the packages available in the overlay to your environment. `setup` sources the overlay as well as the underlay it was created in, allowing you to utilize both workspaces. So, sourcing your main ROS 2 installation’s `setup` and then the `ros2_ws` overlay’s `local_setup`, like you just did, is the same as just sourcing `ros2_ws`’s `setup`, because that includes the environment of its underlay.

### Queue size
Queue size is a required QoS (quality of service) setting that limits the amount of queued messages if a subscriber is not receiving them fast enough.

## YAML FILES
Usage: YAML is commonly used in ROS 2 for configuration files, particularly for defining parameters for nodes. It provides a human-readable way to specify settings that nodes can read at runtime. Example: A YAML file might define parameters for a robot’s sensor configuration or control settings.

## XML in ROS 2
Usage: While YAML is more commonly used for parameters, XML is still relevant in ROS 2, particularly for defining launch files in the older ROS 1 style. However, ROS 2 primarily uses Python for launch files, which can also include XML-like syntax.

## Launch
In the Robot Operating System (ROS), a launch file is an XML file that is used to start multiple nodes and set parameters in a convenient way. Launch files allow you to configure and run your ROS applications with a single command, making it easier to manage complex systems that involve multiple nodes and configurations.

To pass desired args without changing the entire code:
```bash
//Arguments (pass arguments as '<name>::=<value>'):
'turtlesim_ns':
no description given
(default: 'turtlesim1')

'use_provided_red':
no description given
(default: 'False')

'new_background_r':
no description given
(default: '200')

ros2 launch launch_tutorial example_substitutions.launch.py turtlesim_ns:='turtlesim3' use_provided_red:='True' new_background_r:=200
```

### setup.py
- **os**: This module provides a way of using operating system-dependent functionality like reading or writing to the file system. It is utilized in conjunction with other functions to ensure that the paths to files and directories are correctly formatted and accessible.
- **glob**: This function is used to retrieve files/pathnames matching a specified pattern. It is useful for finding files in a directory.
- **setup tools**: This is a Python package used for packaging Python projects. The `setup` function is used to define the package's metadata and configuration.
- **FindPackageShare**: A substitution that helps locate the share directory of a specified package. This is useful for finding resources like launch files, configuration files, etc.
- **LaunchDescription**: A class that represents the entire launch description, which is a collection of actions to be executed when the launch file is run.
- **IncludeLaunchDescription**: An action that allows you to include another launch file within the current launch file.
- **PythonLaunchDescriptionSource**: A source that specifies that the included launch file is a Python launch file.
- **PathJoinSubstitution**: A substitution that joins multiple path components into a single path. You provide a list of path components (e.g., directory names and file names) to `PathJoinSubstitution`, and it concatenates them into a single path string. It automatically handles the necessary slashes between components, so you don't have to worry about adding them manually (doesn’t matter which OS).

```python
from launch.actions import DeclareLaunchArgument, ExecuteProcess, TimerAction
```
Imports several actions:
- **DeclareLaunchArgument**: Used to declare launch arguments that can be passed to the launch file.
- **ExecuteProcess**: Used to execute a shell command as part of the launch process.
- **TimerAction**: Used to introduce a delay before executing subsequent actions.

## Launch is a generic launching framework (not ROS 2 specific) and Launch_ros has ROS 2 specific things, like nodes that we import here.

### Including a launch file
Including a launch file means referencing another launch file inside a main launch file, allowing modular and reusable configuration.

ROS 2 does not assume which files should be installed or used—this gives you flexibility. If it automatically included all launch files, it could cause issues with unwanted files being installed.

## EVENT HANDLER
**Events**: Refers to a mechanism for signaling that something has occurred within the system, allowing nodes to respond to changes in state or conditions. Can be handled by event handlers.

### Event Handler
- **OnExecutionComplete**, **OnProcessExit**, **OnProcessIO**, **OnProcessStart**, **OnShutdown**: Event handlers that respond to specific events in the launch process.
- With Event Handlers: In the previous example you provided (which included event handlers), the launch file used `RegisterEventListener` to respond to specific events during the execution of the launch process. For example, it could log messages when a process starts or exits, or it could trigger actions based on the completion of other processes.
- Without Event Handlers: The current launch file does not include any event handlers. It simply executes processes in a linear fashion without responding to the state of those processes. This means that it does not have the capability to react dynamically to changes in the system or to the completion of tasks.

```python
//OnProcessIO event handler is used to register a callback function that is executed when the spawn_turtle action writes to its standard output.
//EmitEvent Action: The event handler also executes the EmitEvent action, which emits a Shutdown event. This is a signal to the launch system that it should begin the shutdown process for the entire launch configuration.
```

## LARGE PROJECTS
### Transform Framework
**Transform Framework** is a library that provides a way to keep track of multiple coordinate frames and their relationships over time. It is essential for understanding the spatial relationships between different parts of a robot, sensors, and the environment.

### TF broadcaster
A **TF broadcaster** is a node that publishes the transformation data between different coordinate frames, allowing other nodes to understand the spatial relationships between them. Conversely, a **TF listener** is a node that subscribes to these transformations, enabling it to retrieve and use the transformation data for tasks like positioning and navigation.

```python
//get_package_share_directory: the primary purpose is to provide a way to access the file system path of a package's share directory, which contains files that are meant to be shared with other packages or users.
//  /* wildcards
```

### Environment Variables
Environment variables in ROS 2 are used to customize the behavior of the ROS 2 system without modifying the source code. They can control settings such as logging levels, paths to resources, and configurations for specific nodes or packages.

## TF2
```bash
ros2 run tf2_tools view_frames
```
Here a `tf2` listener is listening to the frames that are being broadcast over ROS and drawing a tree of how the frames are connected.

### FRAMES
Frames are like imaginary boxes or reference points in space that help us understand where things are located and how they are oriented. Think of them as a way to describe positions and directions in a 3D world. Frames tell us the following:
1. Position
2. Orientation
3. Different parts relate to each other in terms of position not just that particular element
4. Dynamic Changes: As the robot moves, the frames can change. For example, if the robot moves forward, the base frame moves, and so does the camera frame. Frames help us keep track of these changes over time.

### RVIZ
**RVIz** (short for Robot Visualization) is a powerful visualization tool used in the Robot Operating System (ROS) and ROS 2. It provides a graphical interface that allows developers and researchers to visualize the state of a robot, its environment, and the data being processed by various sensors and algorithms.

### Static Transform
A **Static Transform** refers to a fixed relationship between two coordinate frames that does not change over time. This means that the position and orientation of one frame relative to another remain constant throughout the operation of the robot, e.g., the position of sensors with respect to each other in a robot.

### Transform Stamped Message
Contains:
1. Timestamp
2. Parent Frame: reference coordinate frame usually called 'world'
3. Child frame: the name of the object being transformed

## EULER vs QUATERNION
- **Quaternion** takes the shortest path always, no gimbal lock. Each orientation needs to be less than 180 degrees. 4-dimensional. Known as SLERP: Spherical Linear Interpolation.
- **Euler angles** cause a problem when you rotate in 90 degrees; you lose one degree of freedom.

```cpp
setRPY(roll, pitch, yaw)
```
Automatically converts Euler angles to a quaternion in C++.

### IMPLICIT EXPLICIT CONVERSION
Broadcasts transformations dynamically: continuously updating and sharing the position and orientation of a moving object (like the turtle in Turtlesim) with other ROS nodes.

```bash
ros2 run tf2_ros tf2_echo world turtle1
```
- `tf2_ros`: package name
- `tf2_echo`: executable that prints the transformation between two frames
- `world`: parent frame
- `turtle1`: child frame

We’re using launch files so that we don't have to use multiple terminals.

```cpp
std::ostringstream stream; stream << "/" << turtlename_c_str() << "/pose"; std::string topic_name = stream.str();
```
This results in a dynamic topic name.

//write about make package xml setup.py files difference
```
