# Define minimum cmake version
cmake_minimum_required(VERSION 3.8)

# Define C++ standard to use
set(CMAKE_CXX_STANDARD 17)

# Project name
project("arke")

# Add coverage
SET(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
SET(GCC_COVERAGE_LINK_FLAGS    "-lgcov")

add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})


# Add executable
add_library(
    arke
    Sources/arke/Dependency.cxx Sources/arke/Dependency.hxx
    Sources/arke/DependencyBuilder.cxx Sources/arke/DependencyBuilder.hxx
    Sources/arke/Package.cxx Sources/arke/Package.hxx
)
target_link_libraries(
	arke
	${GCC_COVERAGE_LINK_FLAGS}
)


# Add test executable
add_executable(
	arke_test
	Tests/main.cxx
	Tests/arke/Dependency_test.cxx
	Tests/arke/Package_test.cxx
)
target_include_directories(
	arke_test
	
	PRIVATE
		Sources
)
target_link_libraries(
	arke_test
	arke
	${GCC_COVERAGE_LINK_FLAGS}
)
