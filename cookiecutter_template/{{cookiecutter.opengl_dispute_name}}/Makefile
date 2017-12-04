BUILD_DIRECTORY := build
USER := $(shell id -u)
GROUP := $(shell id -g)
IMAGE_NAME := crashmaster/opengl_disputes

DOCKER_BUILD := docker build --force-rm=true --tag=${IMAGE_NAME} .
DOCKER_VOLUME := --volume=${PWD}:/{{cookiecutter.opengl_dispute_name}}
DOCKER_USER := --user=${USER}:${GROUP}
DOCKER_AUTOREMOVE_CONTAINER := --rm=true
DOCKER_RUN_OPTIONS := ${DOCKER_AUTOREMOVE_CONTAINER} ${DOCKER_VOLUME} ${DOCKER_USER}
DOCKER_RUN := docker run ${DOCKER_RUN_OPTIONS} ${IMAGE_NAME} bash -c

COMPILE_DISPUTE := "cd /{{cookiecutter.opengl_dispute_name}}/build && make"
MAKE_BUILD_DIRECTORY := "mkdir -p /{{cookiecutter.opengl_dispute_name}}/build"
MAKE_MAKE := "cd /{{cookiecutter.opengl_dispute_name}}/build && cmake .."
EXECUTE_DISPUTE := "cd /{{cookiecutter.opengl_dispute_name}}/build && ./{{cookiecutter.opengl_dispute_name}}"
PRINT_DISPUTE_VERSION := "cd /{{cookiecutter.opengl_dispute_name}}/build && ./{{cookiecutter.opengl_dispute_name}} --version"

export CC := clang
export CXX := clang++

.DEFAULT_GOAL := execute_dispute

compile_dispute: make_make
	@${DOCKER_RUN} ${COMPILE_DISPUTE}

docker_build:
	@${DOCKER_BUILD}

execute_dispute: compile_dispute
	@echo
	@echo "Execute OpenGL Dispute: {{cookiecutter.opengl_dispute_name}}"
	@echo
	@${DOCKER_RUN} ${EXECUTE_DISPUTE}

help:
	@echo "usage:"
	@echo "  make compile_dispute             compile this project"
	@echo "  make [execute_dispute]           create a new project"
	@echo "  make help                        display this help"
	@echo "  make make_make                   create Makefiles with CMake"

make_build_directory: docker_build
	@${DOCKER_RUN} ${MAKE_BUILD_DIRECTORY}

make_make: make_build_directory
	@${DOCKER_RUN} ${MAKE_MAKE}

print_dispute_version: compile_dispute
	@${DOCKER_RUN} ${PRINT_DISPUTE_VERSION}

.PHONY: \
	compile_dispute \
	docker_build \
	execute_dispute \
	help \
	make_build_directory \
	make_make \
	print_dispute_version
