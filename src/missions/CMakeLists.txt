cmake_minimum_required(VERSION 3.8)
project(missions)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()
# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
	set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	add_compile_options(-Wall -Wextra -Wpedantic)
endif()
# Adicione esta linha ANTES do find_package
set(px4_msgs_DIR "/home/marco/projects/PX4-Autopilot/sim_ws/install/px4_msgs/share/px4_msgs/cmake")

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(eigen3_cmake_module REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(px4_msgs REQUIRED)

find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(rclpy REQUIRED)
find_package(rclcpp_action REQUIRED)

find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)



find_package(tf2_ros REQUIRED)

#################
# Setup targets #
#################

include_directories(include)

# Add frame_transforms lib
add_library(frame_transforms SHARED src/lib/frame_transforms.cpp)
ament_target_dependencies(frame_transforms Eigen3 geometry_msgs sensor_msgs)
target_include_directories(frame_transforms PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}>
	$<INSTALL_INTERFACE:include/${PROJECT_NAME}>
)

#swarm drones
add_executable(offboard1 src/offboard1.cpp)
ament_target_dependencies(offboard1 rclcpp px4_msgs  rclcpp_action builtin_interfaces)
install(TARGETS offboard1 DESTINATION lib/${PROJECT_NAME})

add_executable(offboard2 src/offboard2.cpp)
ament_target_dependencies(offboard2 rclcpp px4_msgs  rclcpp_action builtin_interfaces)
install(TARGETS offboard2 DESTINATION lib/${PROJECT_NAME})

add_executable(offboard3 src/offboard3.cpp)
ament_target_dependencies(offboard3 rclcpp px4_msgs  rclcpp_action builtin_interfaces)
install(TARGETS offboard3 DESTINATION lib/${PROJECT_NAME})

add_executable(offboard4 src/offboard4.cpp)
ament_target_dependencies(offboard4 rclcpp px4_msgs  rclcpp_action builtin_interfaces)
install(TARGETS offboard4 DESTINATION lib/${PROJECT_NAME})

add_executable(offboard5 src/offboard5.cpp)
ament_target_dependencies(offboard5 rclcpp px4_msgs  rclcpp_action builtin_interfaces)
install(TARGETS offboard5 DESTINATION lib/${PROJECT_NAME})

add_executable(offboard_master src/offboard_master.cpp)
ament_target_dependencies(offboard_master rclcpp px4_msgs  builtin_interfaces)
install(TARGETS offboard_master DESTINATION lib/${PROJECT_NAME})

add_executable(offboard_mission src/offboard_mission.cpp)
ament_target_dependencies(offboard_mission rclcpp px4_msgs  builtin_interfaces)
install(TARGETS offboard_mission DESTINATION lib/${PROJECT_NAME})



# O seu novo executável apenas vincula com a biblioteca criada
add_executable(joy_offboard src/joy_offboard.cpp src/offboard.cpp)
ament_target_dependencies(joy_offboard rclcpp px4_msgs builtin_interfaces sensor_msgs)
target_include_directories(joy_offboard PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS joy_offboard DESTINATION lib/${PROJECT_NAME})


add_executable(main src/main.cpp src/offboard.cpp)
ament_target_dependencies(main rclcpp px4_msgs builtin_interfaces)
target_include_directories(main PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS main DESTINATION lib/${PROJECT_NAME})

add_executable(nav2_px4_bridge src/offboard_nav.cpp)
ament_target_dependencies(nav2_px4_bridge
  rclcpp
  geometry_msgs
  px4_msgs
  tf2_ros
)


add_executable(offboard_vel src/offboard_vel_control.cpp)
ament_target_dependencies(offboard_vel rclcpp px4_msgs  rclcpp_action builtin_interfaces)
install(TARGETS offboard_vel DESTINATION lib/${PROJECT_NAME})

add_executable(offboard_acc src/offboard_acc_control.cpp)
ament_target_dependencies(offboard_acc rclcpp px4_msgs  rclcpp_action builtin_interfaces)
install(TARGETS offboard_acc DESTINATION lib/${PROJECT_NAME})

############
# Install ##
############

# Export information to downstream packages
ament_export_dependencies(ament_cmake rclcpp rosidl_default_runtime eigen3_cmake_module Eigen3 px4_msgs s geometry_msgs sensor_msgs)

ament_export_targets(export_frame_transforms HAS_LIBRARY_TARGET)

ament_export_include_directories(include)
ament_export_libraries(frame_transforms)

# Install header files
install(DIRECTORY include/${PROJECT_NAME}/ DESTINATION include/${PROJECT_NAME})

install(TARGETS frame_transforms
	EXPORT export_frame_transforms
	ARCHIVE DESTINATION lib
	LIBRARY DESTINATION lib
	RUNTIME DESTINATION bin
	INCLUDES DESTINATION include
)
install(TARGETS
  nav2_px4_bridge
  DESTINATION lib/${PROJECT_NAME}
)
# Install launch files.
install(DIRECTORY launch config DESTINATION share/${PROJECT_NAME}/)

# Install tests
install(DIRECTORY test DESTINATION share/${PROJECT_NAME}/)


# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)


ament_package()
