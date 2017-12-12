BUILD_DIRECTORY := build
USER := $(shell id -u)
GROUP := $(shell id -g)
IMAGE_NAME := crashmaster/opengl_disputes

DOCKER_AUTOREMOVE_CONTAINER := --rm=true
DOCKER_ENV := --env DISPLAY=${DISPLAY}
DOCKER_INTERACTIVE := --tty=true --interactive=true
DOCKER_USER := --user=${USER}:${GROUP}
DOCKER_VOLUMES := --volume=${PWD}:/{{cookiecutter.opengl_dispute_name}} --volume=/tmp/.X11-unix:/tmp/.X11-unix

DOCKER_RUN_OPTIONS := ${DOCKER_AUTOREMOVE_CONTAINER} ${DOCKER_ENV} ${DOCKER_INTERACTIVE} ${DOCKER_USER} ${DOCKER_VOLUMES}

DOCKER_BUILD_COMMAND := docker build --pull --force-rm=true --tag=${IMAGE_NAME} .
DOCKER_RUN_COMMAND := docker run ${DOCKER_RUN_OPTIONS} ${IMAGE_NAME}

DOCKER_SHELL := bash
COMPILE_DISPUTE := bash -c "cd /{{cookiecutter.opengl_dispute_name}}/build && make"
EXECUTE_DISPUTE := bash -c "cd /{{cookiecutter.opengl_dispute_name}}/build && ./{{cookiecutter.opengl_dispute_name}}"
MAKE_BUILD_DIRECTORY := bash -c "mkdir -p /{{cookiecutter.opengl_dispute_name}}/build"
MAKE_MAKE := bash -c "cd /{{cookiecutter.opengl_dispute_name}}/build && cmake .."
PRINT_DISPUTE_VERSION := bash -c "cd /{{cookiecutter.opengl_dispute_name}}/build && ./{{cookiecutter.opengl_dispute_name}} --version"

export CC := clang
export CXX := clang++

.DEFAULT_GOAL := execute_dispute

compile_dispute: make_make
	@${DOCKER_RUN_COMMAND} ${COMPILE_DISPUTE}

build_docker:
	@${DOCKER_BUILD_COMMAND}

docker_shell: build_docker
	@${DOCKER_RUN_COMMAND} ${DOCKER_SHELL}

execute_dispute: compile_dispute
	@echo
	@echo "Execute OpenGL Dispute: {{cookiecutter.opengl_dispute_name}}"
	@echo
	@${DOCKER_RUN_COMMAND} ${EXECUTE_DISPUTE}

help:
	@echo "usage:"
	@echo "  make compile_dispute             compile this project"
	@echo "  make [execute_dispute]           create a new project"
	@echo "  make help                        display this help"
	@echo "  make make_make                   create Makefiles with CMake"

make_build_directory: build_docker
	@${DOCKER_RUN_COMMAND} ${MAKE_BUILD_DIRECTORY}

make_make: make_build_directory
	@${DOCKER_RUN_COMMAND} ${MAKE_MAKE}

print_dispute_version: compile_dispute
	@${DOCKER_RUN_COMMAND} ${PRINT_DISPUTE_VERSION}

.PHONY: \
	build_docker \
	compile_dispute \
	execute_dispute \
	help \
	make_build_directory \
	make_make \
	print_dispute_version
