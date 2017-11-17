#ifndef {{cookiecutter.opengl_dispute_name|upper}}_OPENGL_WINDOW_HPP_
#define {{cookiecutter.opengl_dispute_name|upper}}_OPENGL_WINDOW_HPP_


#include "glad/glad.h"
#include "GLFW/glfw3.h"


GLFWwindow* create_opengl_window(
  void
);

GLFWwindow* create_window_and_opengl_context(
  void
);

void make_opengl_context_current_for_window(
  GLFWwindow*
);

void on_window_size_change(
  GLFWwindow* window,
  int width,
  int height
);

void register_callback_for_window_size_change(
  GLFWwindow* window
);

void set_hinsts_for_window_create(
  void
);


#endif
