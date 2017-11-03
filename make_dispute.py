#!/usr/bin/env python

import argparse
import os
import re
import sys

from cookiecutter.main import cookiecutter


def main():
    command_line_arguments = parse_command_line_arguments()
    extra_context = create_extra_context(command_line_arguments)
    call_cookiecutter(command_line_arguments, extra_context)


def parse_command_line_arguments():
    argument_parser = argparse.ArgumentParser()
    argument_parser.add_argument(
        "--template",
        default="./cookiecutter_template"
    )
    argument_parser.add_argument(
        "--dispute-name",
        default=os.environ.get("DISPUTE_NAME", get_default_dispute_name())
    )

    return argument_parser.parse_args()


def get_default_dispute_name():
    directory_name_pattern = re.compile(r"^dispute_\d+$")
    directory_sequence_numbers = [
        int(x[x.index("_") + 1:])
        for x in os.listdir(os.path.dirname(__file__))
        if os.path.isdir(x) and directory_name_pattern.match(x)
    ]
    return "dispute_{}".format(max(directory_sequence_numbers or [0]) + 1)


def create_extra_context(command_line_arguments):
    return {
        "glfw_include_directory": get_glfw_include_directory(command_line_arguments),
        "opengl_dispute_name": command_line_arguments.dispute_name,
    }


def get_glfw_include_directory(command_line_arguments):
    directory_of_this_file = os.path.abspath(os.path.dirname(__file__))
    return os.path.join(
        directory_of_this_file,
        command_line_arguments.dispute_name,
        "build/glfw-src/include"
    )


def call_cookiecutter(command_line_arguments, extra_context):
    cookiecutter(
        extra_context=extra_context,
        no_input=True,
        overwrite_if_exists=False,
        template=command_line_arguments.template,
    )


if __name__ == "__main__":
    sys.exit(main())
