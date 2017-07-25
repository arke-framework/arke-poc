# Define minimum cmake version
cmake_minimum_required(VERSION 3.8)

# Define C++ standard to use
set(CMAKE_CXX_STANDARD 17)

# Project name
project("arke")

# Add executable
add_executable(
    arke
    Sources/main.cxx
    Sources/arke/Package.hxx
    Sources/arke/Package.cxx
)


# Add test executable
add_executable(
	arke_test
	Tests/main.cxx
)
