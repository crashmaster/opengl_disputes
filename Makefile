.DEFAULT_GOAL := create_new_dispute
TEST_DISPUTE_NAME := test_dispute


compile_test_dispute: create_test_dispute
	cd ${TEST_DISPUTE_NAME} && make compile_dispute

call_cookiecutter_using_tox: check_existence_of_tox
	@tox

check_existence_of_tox:
	@which tox > /dev/null 2>&1

create_new_dispute: call_cookiecutter_using_tox

create_test_dispute:
	@DISPUTE_NAME=${TEST_DISPUTE_NAME} tox

help:
	@echo "usage:"
	@echo "  make help                        display this help"
	@echo "  make [create_new_dispute]        create a new project"

remove_previous_test_dispute:
	@rm -rf ${TEST_DISPUTE_NAME}

run_tests: remove_previous_test_dispute compile_test_dispute
	@cd ${TEST_DISPUTE_NAME} && ./build/${TEST_DISPUTE_NAME} --version


.PHONY: \
	compile_test_dispute \
	call_cookiecutter_using_tox \
	check_existence_of_tox \
	create_new_dispute \
	create_test_dispute \
	help \
	remove_previous_test_dispute \
	run_tests
