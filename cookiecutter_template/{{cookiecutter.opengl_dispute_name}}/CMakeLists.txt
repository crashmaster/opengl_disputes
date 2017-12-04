cmake_minimum_required(VERSION 3.1)

project({{cookiecutter.opengl_dispute_name}})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")

include(DownloadProject.cmake)

download_project(
    PROJ                glfw
    GIT_REPOSITORY      https://github.com/glfw/glfw.git
    GIT_TAG             3.2.1
    ${UPDATE_DISCONNECTED_IF_AVAILABLE}
)

add_subdirectory(
    ${glfw_SOURCE_DIR}
    ${glfw_BINARY_DIR}
)

include_directories(
    glad/include
)

add_executable(
    {{cookiecutter.opengl_dispute_name}}
    glad/src/glad.c
    src/{{cookiecutter.opengl_dispute_name}}_command_line_options.cpp
    src/{{cookiecutter.opengl_dispute_name}}_main.cpp
    src/{{cookiecutter.opengl_dispute_name}}_main_loop.cpp
    src/{{cookiecutter.opengl_dispute_name}}_opengl_window.cpp
)

target_link_libraries(
    {{cookiecutter.opengl_dispute_name}}
        glfw
        boost_program_options
)
