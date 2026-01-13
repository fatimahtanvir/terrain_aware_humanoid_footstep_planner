cmake_minimum_required(VERSION 3.8)
project(footstep_planner)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

include_directories(include)

add_executable(footstep_planner_node
  src/planner.cpp
  src/footstep_planner_node.cpp
)

ament_target_dependencies(footstep_planner_node rclcpp)

install(TARGETS footstep_planner_node
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY include/
  DESTINATION include/)

ament_package()
