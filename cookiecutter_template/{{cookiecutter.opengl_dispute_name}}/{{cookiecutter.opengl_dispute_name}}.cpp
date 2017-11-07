#include <iostream>

#include <boost/program_options.hpp>

#include "glad/glad.h"
#include "GLFW/glfw3.h"


int parse_program_options(int argc, char* argv[]);


int parse_program_options(int argc, char* argv[]) {
  boost::program_options::options_description generic_options("Generic options");

  generic_options.add_options()
    ("version,v", "print version string")
  ;

  boost::program_options::options_description command_line_options;
  command_line_options.add(generic_options);

  boost::program_options::variables_map variables_map;
  store(boost::program_options::command_line_parser(argc, argv).
    options(command_line_options).run(), variables_map);
  notify(variables_map);

  if (variables_map.count("version")) {
    std::cout << "Version 1.0" << std::endl;
  }

  return 0;
}


int main(int argc, char* argv[]) {
  std::cout << "OpenGL Dispute: {{cookiecutter.opengl_dispute_name}}" << std::endl;

  parse_program_options(argc, argv);

  return 0;
}
