cmake_minimum_required(VERSION 3.5)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_definitions(-std=c++20 -g -O0)
#add_definitions(-DDEBUG)
set(CMAKE_CXX_STANDARD 20)

add_library(cpu_65C816 SHARED cpu_65C816.cpp cpu_65C816.hpp cpu_65C816_instruction_set.cpp cpu_65C816_instruction_set.hpp)
set_target_properties(cpu_65C816 PROPERTIES PUBLIC_HEADER cpu_65C816.hpp)

target_include_directories(cpu_65C816 PRIVATE ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(cpu_65C816 PRIVATE snes_memory)
target_include_directories(cpu_65C816 PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../memory)

add_subdirectory(tests)
