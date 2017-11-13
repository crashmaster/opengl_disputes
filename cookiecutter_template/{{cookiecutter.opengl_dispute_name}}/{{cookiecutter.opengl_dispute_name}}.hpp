#ifndef {{cookiecutter.opengl_dispute_name|upper}}_HPP_
#define {{cookiecutter.opengl_dispute_name|upper}}_HPP_


#include "glad/glad.h"
#include "GLFW/glfw3.h"


GLFWwindow* create_opengl_window(
  void
);

void initialize_glad_extension_loader_library(
  void
);

void initialize_glfw_library(
  void
);

void make_opengl_context_current_of_window(
  GLFWwindow*
);

void on_resize(
  GLFWwindow* window,
  int width,
  int height
);

void process_input(
  GLFWwindow* window
);

void set_opengl_version(
  void
);

void set_on_resize_callback(
  GLFWwindow* window
);

GLFWwindow* set_up_opengl_window(
  void
);


#endif
