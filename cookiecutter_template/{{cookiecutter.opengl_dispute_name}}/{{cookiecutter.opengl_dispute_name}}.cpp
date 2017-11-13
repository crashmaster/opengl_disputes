#include "{{cookiecutter.opengl_dispute_name}}.hpp"

#include <cstdlib>
#include <iostream>
#include <stdexcept>


int process_command_line_options(
  int argc,
  const char* const argv[]
) {
  auto options = add_generic_options();
  auto variables_map = parse_command_line_options(argc, argv, options);
  act_on_set_command_line_options(variables_map);
  return 0;
}


po::options_description add_generic_options(
  void
) {
  po::options_description options("Generic options");

  options.add_options()
    ("version,v", "print version string")
  ;

  return options;
}


po::variables_map parse_command_line_options(
  int argc,
  const char* const argv[],
  const po::options_description& options
) {
  po::options_description command_line_options;
  command_line_options.add(options);

  po::variables_map variables_map;
  store(po::command_line_parser(argc, argv).
    options(command_line_options).run(), variables_map);
  notify(variables_map);

  return variables_map;
}


void act_on_set_command_line_options(
  const po::variables_map& variables_map
) {
  if (variables_map.count("version")) {
    std::string version_string(
      "OpenGL Dispute: {{cookiecutter.opengl_dispute_name}}\n"
      "Version: 1.0.1"
    );
    std::cout << version_string << std::endl;
    std::exit(EXIT_SUCCESS);
  }
}


void process_input(
  GLFWwindow *window
) {
  if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
}


GLFWwindow* set_up_opengl_window(
  void
) {
  initialize_glfw_library();
  set_opengl_version();
  GLFWwindow* window = create_opengl_window();
  make_opengl_context_current_of_window(window);
  set_on_resize_callback(window);
  initialize_glad_extension_loader_library();
  return window;
}


void initialize_glfw_library(
  void
) {
  glfwInit();
}


void set_opengl_version(
  void
) {
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}


GLFWwindow* create_opengl_window(
  void
) {
  auto window = glfwCreateWindow(800, 600, "{{cookiecutter.opengl_dispute_name}}", NULL, NULL);
  if (window == NULL) {
    throw std::runtime_error("Failed to create GLFW window");
  }
  return window;
}


void make_opengl_context_current_of_window(
  GLFWwindow* window
) {
  glfwMakeContextCurrent(window);
}


void on_resize(
  GLFWwindow* window,
  int width,
  int height
) {
  glViewport(0, 0, width, height);
}


void set_on_resize_callback(
  GLFWwindow* window
) {
  glfwSetFramebufferSizeCallback(window, on_resize);
}


void initialize_glad_extension_loader_library(
  void
) {
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    throw std::runtime_error("Failed to initialize GLAD");
  }
}


int main(
  int argc,
  char* argv[]
) {
  process_command_line_options(argc, argv);
  GLFWwindow* window = set_up_opengl_window();

  while (!glfwWindowShouldClose(window)) {
    process_input(window);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
