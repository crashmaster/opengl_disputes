//#ifndef {{cookiecutter.opengl_dispute_name|upper}}_HPP
//#define {{cookiecutter.opengl_dispute_name|upper}}_HPP


#include <boost/program_options.hpp>


namespace po = boost::program_options;


int process_command_line_options(
  int argc,
  const char* const argv[]
);

po::options_description add_generic_options();

po::variables_map parse_command_line_options(
  int argc,
  const char* const argv[],
  const po::options_description&
);

void act_on_set_command_line_options(
  const po::variables_map& variables_map
);


//#endif
