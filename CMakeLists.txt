cmake_minimum_required(VERSION 2.8.3)
project(hauv_udp_comm)
find_package(catkin REQUIRED COMPONENTS
  roscpp
)
set(SOURCES src/hauv_udp_comm_node.cpp src/udp_listen_socket.cpp)

## System dependencies are found with CMake's conventions
find_package(Threads)

catkin_package(
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}_node ${SOURCES})

target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
  ${CMAKE_THREAD_LIBS_INIT}
)


