# Define minimum cmake version
cmake_minimum_required(VERSION 3.8)

# Enable test
enable_testing()

# Define C++ standard to use
set(CMAKE_CXX_STANDARD 17)

# Project name
project("arke")

# Find boost
find_package(Boost 1.54 COMPONENTS filesystem)

# Find botan
find_path(BOTAN_INCLUDE_DIRS NAMES botan/botan.h PATH_SUFFIXES botan-2)
find_library(BOTAN_LIBRARIES NAMES botan botan-2)

message("-- Includes ${BOTAN_INCLUDE_DIRS}")
message("-- Library ${BOTAN_LIBRARIES}")

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
    
    Sources/crypto/SHAGenerator.cxx Sources/crypto/SHAGenerator.hxx
    
    Sources/dependency/Dependency.cxx Sources/dependency/Dependency.hxx
    Sources/dependency/DependencyDefinition.cxx Sources/dependency/DependencyDefinition.hxx
    Sources/dependency/DependencyBuilder.cxx Sources/dependency/DependencyBuilder.hxx
    
    Sources/files/HashFile.cxx Sources/files/HashFile.hxx
    Sources/files/FilesGroup.cxx Sources/files/FilesGroup.hxx
    Sources/files/FilesGroupBuilder.cxx Sources/files/FilesGroupBuilder.hxx
    
    Sources/package/Package.cxx Sources/package/Package.hxx
    Sources/package/PackageBuilder.cxx Sources/package/PackageBuilder.hxx
    
    Sources/version/VersionMatcher.cxx Sources/version/VersionMatcher.hxx
)
target_include_directories(
	arke
	
	PRIVATE
		${BOTAN_INCLUDE_DIRS}
		${Boost_INCLUDE_DIRS}
)
target_link_libraries(
	arke
	${COVERAGE_LINK_FLAGS}
	${BOTAN_LIBRARIES}
)
target_include_directories(
	arke
	
	PRIVATE
		Sources
)

# Add test executable
add_executable(
	arke_test
	Tests/main.cxx
	Tests/arke/Dependency_test.cxx
	Tests/arke/Package_test.cxx
	Tests/arke/DependencyDefinition_test.cxx
	Tests/arke/VersionMatcher_test.cxx
	Tests/arke/HashFile_test.cxx
	Tests/arke/FilesGroup_test.cxx
	Tests/arke/tools/SHAGenerator_test.cxx
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
	${BOTAN_LIBRARIES}
	${Boost_LIBRARIES}
)

# Register test
add_test(arke_test arke_test)
