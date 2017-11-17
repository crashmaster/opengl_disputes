#include "{{cookiecutter.opengl_dispute_name}}_command_line_options.hpp"

#include <iostream>
#include <string>

#include <boost/program_options.hpp>


namespace po = boost::program_options;


namespace {
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


  po::options_description add_command_line_options(
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
}


int process_command_line_options(
  int argc,
  const char* const argv[]
) {
  auto options = add_command_line_options();
  auto variables_map = parse_command_line_options(argc, argv, options);
  act_on_set_command_line_options(variables_map);
  return 0;
}
