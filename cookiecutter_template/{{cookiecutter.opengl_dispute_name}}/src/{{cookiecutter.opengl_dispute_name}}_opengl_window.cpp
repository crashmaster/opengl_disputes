#include "{{cookiecutter.opengl_dispute_name}}_opengl_window.hpp"

#include <stdexcept>


namespace {
  GLFWwindow* create_window_and_opengl_context(
    void
  ) {
    auto window = glfwCreateWindow(
      800,
      600,
      "{{cookiecutter.opengl_dispute_name}}",
      NULL,
      NULL
    );
    if (window == NULL) {
      throw std::runtime_error("Failed to create GLFW window");
    } else {
      return window;
    }
  }


  void make_opengl_context_current_for_window(
    GLFWwindow* window
  ) {
    glfwMakeContextCurrent(window);
  }


  void register_callback_for_window_size_change(
    GLFWwindow* window,
    GLFWframebuffersizefun on_window_size_change
  ) {
    glfwSetFramebufferSizeCallback(window, on_window_size_change);
  }


  void on_window_size_change(
    GLFWwindow* window,
    int width,
    int height
  ) {
    glViewport(0, 0, width, height);
  }


  void set_hinsts_for_window_create(
    void
  ) {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  }
}


GLFWwindow* create_opengl_window(
  void
) {
  set_hinsts_for_window_create();
  GLFWwindow* window = create_window_and_opengl_context();
  make_opengl_context_current_for_window(window);
  register_callback_for_window_size_change(window, on_window_size_change);
  return window;
}
