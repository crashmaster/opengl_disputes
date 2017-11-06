import os
import sys


THIS_DIRECTORY = os.path.abspath(os.path.dirname(__file__))


def main():
    with open(os.path.join(THIS_DIRECTORY, "README.md")) as readme:
        commands_to_execute = [
            line for line in readme if " % " in line
        ]
    print(commands_to_execute)


if __name__ == "__main__":
    sys.exit(main())
