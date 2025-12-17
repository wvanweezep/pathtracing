cmake_minimum_required(VERSION 3.31)
project(pathtracing)

set(CMAKE_CXX_STANDARD 23)

add_executable(pathtracing main.cpp
        src/image.cpp
        src/camera.cpp
        src/scene.cpp)

target_include_directories(pathtracing PRIVATE
        external/glm
        external/stb
        include)
