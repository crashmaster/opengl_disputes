import os
import ycm_core

FLAGS = [
    "-Werror",
    "-Weverything",
    "-fexceptions",
    "-std=c++14",
    "-x", "c++",
    "-I", "{{cookiecutter.glfw_include_directory}}",
]


def FlagsForFile(filename, **kwargs):
    return {
        "flags": FLAGS,
    }
