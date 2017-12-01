#include <cstdlib>
#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "{{cookiecutter.opengl_dispute_name}}_command_line_options.hpp"
#include "{{cookiecutter.opengl_dispute_name}}_main_loop.hpp"
#include "{{cookiecutter.opengl_dispute_name}}_opengl_window.hpp"


namespace {
  void destruct_glfw_library(
    void
  ) {
    glfwTerminate();
  }


  void initialize_glfw_library(
    void
  ) {
    glfwInit();
  }


  void initialize_glad_extension_loader_library(
    void
  ) {
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
      throw std::runtime_error("Failed to initialize GLAD");
    }
  }
}


int main(
  int argc,
  char* argv[]
) {
  process_command_line_options(argc, argv);
  initialize_glfw_library();
  GLFWwindow* window = create_opengl_window();
  initialize_glad_extension_loader_library();
  main_loop(window);
  destruct_glfw_library();
  return 0;
}
