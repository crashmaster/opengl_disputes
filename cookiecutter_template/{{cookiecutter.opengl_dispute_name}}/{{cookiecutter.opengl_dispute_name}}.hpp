#ifndef {{cookiecutter.opengl_dispute_name|upper}}_HPP_
#define {{cookiecutter.opengl_dispute_name|upper}}_HPP_


#include "glad/glad.h"
#include "GLFW/glfw3.h"


void destruct_glfw_library(
  void
);

void initialize_glad_extension_loader_library(
  void
);

void initialize_glfw_library(
  void
);

void process_input(
  GLFWwindow* window
);


#endif
