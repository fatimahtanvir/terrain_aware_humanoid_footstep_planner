cmake_minimum_required(VERSION 3.8)
project(footstep_planner)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Footstep.msg"
)

include_directories(include)

add_library(planner
  src/planner.cpp
  src/terrain_utils.cpp
)

ament_target_dependencies(planner rclcpp geometry_msgs)

add_executable(footstep_planner_node src/footstep_planner_node.cpp)
target_link_libraries(footstep_planner_node planner)

ament_target_dependencies(footstep_planner_node rclcpp)

install(TARGETS
  footstep_planner_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
