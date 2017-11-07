BUILD_DIRECTORY := build

.DEFAULT_GOAL := execute_dispute

compile_dispute: make_make
	@cd ${BUILD_DIRECTORY} && make

execute_dispute: compile_dispute
	@echo
	@echo "Execute OpenGL Dispute: {{cookiecutter.opengl_dispute_name}}"
	@echo
	@./${BUILD_DIRECTORY}/{{cookiecutter.opengl_dispute_name}}

make_build_directory:
	@mkdir ${BUILD_DIRECTORY}

make_make: make_build_directory
	@cd ${BUILD_DIRECTORY} && cmake ..

.PHONY: \
	compile_dispute \
	execute_dispute \
	make_build_directory \
	make_make
