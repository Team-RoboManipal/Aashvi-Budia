cmake_minimum_required(VERSION 3.5)
project(polygon_pkg_cpp)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(turtlesim REQUIRED)
find_package(tutorial_interfaces REQUIRED)

add_executable(draw_polygon_server src/service_server.cpp)
ament_target_dependencies(draw_polygon_server rclcpp geometry_msgs turtlesim tutorial_interfaces)

add_executable(polygon_client src/client.cpp)
ament_target_dependencies(polygon_client rclcpp tutorial_interfaces)

install(TARGETS
  draw_polygon_server
  polygon_client
  DESTINATION lib/${PROJECT_NAME})

ament_package()
