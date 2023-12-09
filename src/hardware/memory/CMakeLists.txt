cmake_minimum_required(VERSION 3.5)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_definitions(-std=c++17)
add_definitions(-DDEBUG)
set(CMAKE_CXX_STANDARD 17)

add_library(snes_memory SHARED mem.hpp mem.cpp)
set_target_properties(snes_memory PROPERTIES PUBLIC_HEADER mem.hpp)

target_include_directories(snes_memory PRIVATE ${CMAKE_CURRENT_LIST_DIR})