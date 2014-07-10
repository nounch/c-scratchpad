ECHO = printf "%s\n  "
HLINE = printf "%s\n\n" "---------------------------------------------------------------------------"
# TREE = `tree --noreport`


# target: help - Show available `make' targets.
help:
	@grep "^# target:" [Mm]akefile | sed 's/^# target: //g'

# target: all - Build the `./bin/test' executable from `test.c'.
all: PSEUDO test.c
	@$(ECHO) "Building executable";
	cc -std=c89 -o ./bin/test test.c;
	@$(ECHO) "Running executable";
	@# @printf "\nOVERVIEW:\n---------\n%s\n\n" "$(TREE)";
	@printf "\n"; $(HLINE); ./bin/test;

	@# @printf "%s\n" "$@"
	@# @printf "%s\n" "$?"
	@# @printf "%s\n" "$^"

# target: clean - Clean the repository.
clean:
	rm -rf ./bin/test

PSEUDO:
