#!/bin/bash
set -e
CHAOS_ROOT="$(dirname "$0")/.."
cd "$CHAOS_ROOT"
if [ $# -ge 1 ] ; then
	if [ "$1" == "--dry-run" ] ; then
		find . -type f \( -name "*.h" -or -name "*.cpp" -or -name "*.hpp" \) \
			-and ! -path "*lib*" \
			-and ! -path "*build*" \
			-exec clang-format --dry-run -Werror {} \+
	else
		echo "Invalid arguments"
		exit 2
	fi
else
	find . -type f \( -name "*.h" -or -name "*.cpp" -or -name "*.hpp" \) \
		-and ! -path "*lib*" \
		-and ! -path "*build*" \
		-exec clang-format -i {} \;
fi
