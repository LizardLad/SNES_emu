cmake_minimum_required(VERSION 3.5)

if(EMSCRIPTEN)
add_subdirectory(emscripten)
endif()

add_subdirectory(hardware)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
