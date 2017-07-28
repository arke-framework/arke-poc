
#!/bin/bash

echo " -- Compiler familly ${CXX}"

alias clangcov="llvm-cov gcov"
    
export COV_EXE=lcov
if [ $CXX == "clang"++ ]; then
    export COV_TOOL=ccov
else 
    export CXX=g++
    export COV_TOOL=gcov
fi

# Projects
SCRIPT_DIRECTORY=`dirname "$0"`
PROJECT_DIRECTORY=`readlink -f "$SCRIPT_DIRECTORY/.."`

# Build directory
BUILD_DIRECTORY="${PROJECT_DIRECTORY}/build-report"

# Source directory
SOURCES_DIRECTORY="${PROJECT_DIRECTORY}/Sources"

echo " - Init build directory : ${BUILD_DIRECTORY}"

# Go to build directory
mkdir -p ${BUILD_DIRECTORY}

echo " - Enter to build directory"

cd ${BUILD_DIRECTORY}

echo " - Init cmake"

# Init coverage
cmake -DCMAKE_BUILD_TYPE=Coverage ${PROJECT_DIRECTORY}

echo " - Clean directory : "`pwd`

# Netoyage
rm -fr out
rm -f *.info
make clean

echo " - Build"

# Build
make

echo " - Init ${COV_EXE} : ${COV_EXE} --gcov-tool ${COV_TOOL} -f -c -i --directory ${BUILD_DIRECTORY} -o app_base.info"

# Init test file
${COV_EXE} --gcov-tool ${COV_TOOL} -f -c -i --directory ${BUILD_DIRECTORY} -o app_base.info

echo " - Launch test : make test"

# Launch test
make test

echo " - Collect ${COV_EXE} : ${COV_EXE} --gcov-tool ${COV_TOOL} -f -c --directory ${BUILD_DIRECTORY} -o app_test.info"

# Collect coverage
${COV_EXE} --gcov-tool ${COV_TOOL}  -f -c --directory ${BUILD_DIRECTORY} -o app_test.info

echo " - Filter ${SOURCES_DIRECTORY} : ${COV_EXE} --gcov-tool ${COV_TOOL} -e app_test.info "${SOURCES_DIRECTORY}/*" -o result.info"

echo " - Combine ${COV_EXE} : ${COV_EXE} -a app_base.info -a app_test.info -o app_total.info"

# Combine coverage
${COV_EXE} --gcov-tool ${COV_TOOL} --gcov-tool ${COV_TOOL} -a app_base.info -a app_test.info -o app_total.info

echo " - Filter ${SOURCES_DIRECTORY}"

# Filter results
${COV_EXE} --gcov-tool ${COV_TOOL} -e app_total.info "${SOURCES_DIRECTORY}/*" -o result.info

echo " - Generate report "`pwd`"/out : genhtml result.info --output-directory out"

# Generate HTML result
genhtml --demangle-cpp --branch-coverage --show-details result.info --output-directory out
