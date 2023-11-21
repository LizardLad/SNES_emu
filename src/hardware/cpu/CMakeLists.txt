cmake_minimum_required(VERSION 2.8.3)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_definitions(-std=c++17)
add_definitions(-DDEBUG)
set(CMAKE_CXX_STANDARD 17)

add_library(cpu_65c816 SHARED cpu.cpp cpu.hpp)
set_target_properties(cpu_65c816 PROPERTIES PUBLIC_HEADER cpu.hpp)

target_include_directories(cpu_65c816 PRIVATE .)
