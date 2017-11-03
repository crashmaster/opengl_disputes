.DEFAULT_GOAL := new_dispute

call_cookiecutter_using_tox: check_existence_of_tox
	@tox

check_existence_of_tox:
	@which tox > /dev/null 2>&1

help:
	@echo "usage:"
	@echo "  make help                display this help"
	@echo "  make [new_dispute]       create a new project"

new_dispute: call_cookiecutter_using_tox

.PHONY: \
	call_cookiecutter_using_tox \
	check_existence_of_tox \
	help \
	new_dispute
