#ifndef {{cookiecutter.opengl_dispute_name|upper}}_HPP
#define {{cookiecutter.opengl_dispute_name|upper}}_HPP


#include <boost/program_options.hpp>

#include "glad/glad.h"
#include "GLFW/glfw3.h"


namespace po = boost::program_options;


void act_on_set_command_line_options(
  const po::variables_map& variables_map
);

po::options_description add_generic_options(
  void
);

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

po::variables_map parse_command_line_options(
  int argc,
  const char* const argv[],
  const po::options_description&
);

int process_command_line_options(
  int argc,
  const char* const argv[]
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
