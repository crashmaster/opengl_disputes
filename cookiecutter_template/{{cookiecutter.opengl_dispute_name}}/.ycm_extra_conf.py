import os
import ycm_core

FLAGS = [
    '-Werror',
    '-Weverything',
    '-fexceptions',
    '-std=c++14',
    '-x', 'c++',
]


def FlagsForFile(filename, **kwargs):
  return {
    'flags': FLAGS,
  }
