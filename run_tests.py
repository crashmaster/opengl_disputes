#!/usr/bin/env python

import os
import subprocess
import sys


THIS_DIRECTORY = os.path.abspath(os.path.dirname(__file__))


def main():
    commands_in_readme_md = extract_commands_from_readme_md()
    execute_commands(commands_in_readme_md)


def extract_commands_from_readme_md():
    with open(os.path.join(THIS_DIRECTORY, "README.md")) as readme:
        return [
            line[line.index("%") + 2:].rstrip()
            for line in readme
            if " % " in line
        ]


def execute_commands(commands_in_readme_md):
    for command in commands_in_readme_md:
        subprocess.check_call(command, shell=True)


if __name__ == "__main__":
    sys.exit(main())
