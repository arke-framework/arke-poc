# Define minimum cmake version
cmake_minimum_required(VERSION 3.8)

# Enable test
enable_testing()

# Define C++ standard to use
set(CMAKE_CXX_STANDARD 17)

# Project name
project("arke")

message("-- Compiler familly ${CMAKE_CXX_COMPILER_ID}")
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	# Add coverage
	SET(COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage -stdlib=libc++")
	SET(COVERAGE_LINK_FLAGS    "--coverage  -stdlib=libc++ -lc++abi")
else()	
	# Add coverage
	SET(COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
	SET(COVERAGE_LINK_FLAGS    "-lgcov")
endif()

# Add coverage
add_definitions(${COVERAGE_COMPILE_FLAGS})


# Add executable
add_library(
    arke
    Sources/arke/Dependency.cxx Sources/arke/Dependency.hxx
    Sources/arke/DependencyDefinition.cxx Sources/arke/DependencyDefinition.hxx
    Sources/arke/VersionMatcher.cxx Sources/arke/VersionMatcher.hxx
    Sources/arke/DependencyBuilder.cxx Sources/arke/DependencyBuilder.hxx
    Sources/arke/Package.cxx Sources/arke/Package.hxx
)
target_link_libraries(
	arke
#	${COVERAGE_LINK_FLAGS}
)


# Add test executable
add_executable(
	arke_test
	Tests/main.cxx
	Tests/arke/Dependency_test.cxx
	Tests/arke/Package_test.cxx
	Tests/arke/DependencyDefinition_test.cxx
	Tests/arke/VersionMatcher_test.cxx
)
target_include_directories(
	arke_test
	
	PRIVATE
		Sources
)
target_link_libraries(
	arke_test
	arke
	${COVERAGE_LINK_FLAGS}
)

# Register test
add_test(arke_test arke_test)
