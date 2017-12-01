BUILD_DIRECTORY := build
USER := $(shell id -u)
GROUP := $(shell id -g)
IMAGE_NAME := crashmaster/opengl_disputes

DOCKER_BUILD := docker build --tag=${IMAGE_NAME} .
DOCKER_VOLUME := --volume=${PWD}:/{{cookiecutter.opengl_dispute_name}}
DOCKER_USER := --user=${USER}:${GROUP}
DOCKER_OPTIONS := ${DOCKER_VOLUME} ${DOCKER_USER}
DOCKER_RUN := docker run ${DOCKER_OPTIONS} ${IMAGE_NAME} bash -c

COMPILE_DISPUTE := "cd /{{cookiecutter.opengl_dispute_name}}/build && make"
MAKE_BUILD_DIRECTORY := "mkdir -p /{{cookiecutter.opengl_dispute_name}}/build"
MAKE_MAKE := "cd /{{cookiecutter.opengl_dispute_name}}/build && cmake .."

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
	@./${BUILD_DIRECTORY}/{{cookiecutter.opengl_dispute_name}}

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

.PHONY: \
	compile_dispute \
	docker_build \
	execute_dispute \
	help \
	make_build_directory \
	make_make
