cmake_minimum_required(VERSION 3.5)

project(SNES_EMULATOR)


include_directories(${CMAKE_SOURCE_DIR}/includes)

add_subdirectory(src)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)