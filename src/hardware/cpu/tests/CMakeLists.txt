cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_definitions(-std=c++17)
add_definitions(-DDEBUG)
set(CMAKE_CXX_STANDARD 17)

add_executable(cpu_loop_test cpu_loop.cpp)

target_link_libraries(cpu_loop_test PRIVATE cpu_65C816 snes_memory)
target_include_directories(cpu_loop_test 
	PRIVATE 
	${PROJECT_SOURCE_DIR}/src/hardware/cpu 
	${PROJECT_SOURCE_DIR}/src/hardware/memory 
)
