#ifndef {{cookiecutter.opengl_dispute_name|upper}}_COMMAND_LINE_OPTIONS_HPP_
#define {{cookiecutter.opengl_dispute_name|upper}}_COMMAND_LINE_OPTIONS_HPP_


#include <boost/program_options.hpp>


namespace po = boost::program_options;


void act_on_set_command_line_options(
  const po::variables_map& variables_map
);

po::options_description add_generic_options(
  void
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


#endif
