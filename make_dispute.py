#!/usr/bin/env python

import argparse
import os
import re
import sys

from cookiecutter.main import cookiecutter


THIS_DIRECTORY = os.path.abspath(os.path.dirname(__file__))
COOKIECUTTER_TEMPLATE_PATH = os.path.join(THIS_DIRECTORY, "./cookiecutter_template")
DISPUTE_DIRECTORY_NAME_PREFIX = "dispute_"


def main():
    command_line_arguments = parse_command_line_arguments()
    extra_context = create_extra_context(command_line_arguments)
    call_cookiecutter(command_line_arguments, extra_context)


def parse_command_line_arguments():
    argument_parser = argparse.ArgumentParser()
    argument_parser.add_argument(
        "--template",
        default=COOKIECUTTER_TEMPLATE_PATH
    )
    argument_parser.add_argument(
        "--dispute-name",
        default=os.environ.get("DISPUTE_NAME", get_default_dispute_name())
    )

    return argument_parser.parse_args()


def get_default_dispute_name():
    directory_name_pattern = re.compile(
        r"^{}\d+$".format(DISPUTE_DIRECTORY_NAME_PREFIX)
    )
    directory_sequence_numbers = [
        int(x[x.index("_") + 1:])
        for x in os.listdir(THIS_DIRECTORY)
        if os.path.isdir(x) and directory_name_pattern.match(x)
    ]
    return "{}{}".format(
        DISPUTE_DIRECTORY_NAME_PREFIX,
        max(directory_sequence_numbers or [0]) + 1
    )


def create_extra_context(command_line_arguments):
    return {
        "glfw_include_directory": get_glfw_include_directory(command_line_arguments),
        "opengl_dispute_name": command_line_arguments.dispute_name,
    }


def get_glfw_include_directory(command_line_arguments):
    return os.path.join(
        THIS_DIRECTORY,
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
