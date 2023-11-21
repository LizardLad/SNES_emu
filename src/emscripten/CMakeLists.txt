cmake_minimum_required(VERSION 2.8.3)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_TOOLCHAIN_FILE "${EMROOT}/cmake/Modules/Platform/Emscripten.cmake")
add_definitions(-std=c++17)
set(CMAKE_CXX_STANDARD 17)

add_executable(calc main.cpp)

set(CMAKE_EXECUTABLE_SUFFIX ".wasm")
target_include_directories(calc PRIVATE .)

set(EXECUTABLE_OUTPUT_PATH "../../bin/")

set_target_properties(calc PROPERTIES COMPILE_FLAGS "-Os -s SIDE_MODULE=1 ")
set_target_properties(calc PROPERTIES LINK_FLAGS    "-Os -s WASM=1 -s SIDE_MODULE=1 -s STANDALONE_WASM --no-entry")