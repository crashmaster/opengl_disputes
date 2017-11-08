#include "{{cookiecutter.opengl_dispute_name}}.hpp"

#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"


int process_command_line_options(
  int argc,
  const char* const argv[]
) {
  auto options = add_generic_options();
  auto variables_map = parse_command_line_options(argc, argv, options);
  act_on_set_command_line_options(variables_map);
  return 0;
}


po::options_description add_generic_options() {
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
    std::cout << "Version 1.0" << std::endl;
  }
}


int main(int argc, char* argv[]) {
  std::cout << "OpenGL Dispute: {{cookiecutter.opengl_dispute_name}}" << std::endl;

  process_command_line_options(argc, argv);

  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  return 0;
}
