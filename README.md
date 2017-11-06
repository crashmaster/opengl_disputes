# opengl_disputes
[![Build Status](https://travis-ci.org/crashmaster/opengl_disputes.svg?branch=master)](https://travis-ci.org/crashmaster/opengl_disputes)

Host various OpenGL examples.

# Create a new dispute (a.k.a. project)
```
opengl_disputes % DISPUTE_NAME=test_dispute make
opengl_disputes % mkdir -p test_dispute/build
opengl_disputes % cd test_dispute/build && cmake .. && cd -
opengl_disputes % cd test_dispute/build && make && cd -
opengl_disputes % ./test_dispute/build/test_dispute
```
