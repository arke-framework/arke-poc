#!/bin/bash

# Projects
SCRIPT_DIRECTORY=`dirname "$0"`
PROJECT_DIRECTORY=`readlink -f "$SCRIPT_DIRECTORY"`

# Build directory
BUILD_DIRECTORY="${PROJECT_DIRECTORY}/build-report"

# Source directory
TESTS_DIRECTORY="${PROJECT_DIRECTORY}/Tests"

# Remove
rm -fr ${BUILD_DIRECTORY}

# Launch test coverage
${TESTS_DIRECTORY}/coverage.sh

# Generate documentation
doxygen Doxyfile
