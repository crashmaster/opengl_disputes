def FlagsForFile(filename, **kwargs):
    return {
        "flags": [
            "-Werror",
            "-Weverything",
            "-Wno-c++98-compat-pedantic",
            "-fexceptions",
            "-std=c++14",
            "-x", "c++",
            "-I", "{{cookiecutter.glfw_include_directory}}",
        ]
    }
