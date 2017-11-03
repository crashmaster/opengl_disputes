cmake_minimum_required(VERSION 2.8.2)

project({{cookiecutter.opengl_dispute_name}})

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

add_executable(
    {{cookiecutter.opengl_dispute_name}}
    {{cookiecutter.opengl_dispute_name}}.cpp
)

target_link_libraries(
    {{cookiecutter.opengl_dispute_name}}
        glfw
)