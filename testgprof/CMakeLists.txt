# This CMakeLists.txt only for cmake --version >= 3.5.1
cmake_minimum_required(VERSION 3.5.1)

# project name
project(testcmake)

# Build Type Release for high optimization and no debugging
set(CMAKE_BUILD_TYPE Release)

# Compiler macro: g++ for C++
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

# compiler flags:
set(CMAKE_CXX_STANDARD 11) # set the C++11 standard
set(CMAKE_C_FLAGS "-O3 -pg") # set full optimization and enable profiling
set(CMAKE_CXX_FLAGS "-O3 -pg") # set full optimization and enable profiling

# the build target executable:
set(TARGET main)

# define any directories containing header files other than /usr/include:
include_directories(include)

# define library paths in addition to /usr/lib:
link_directories(lib)

# define the C++ source files:
file(GLOB SRCS src/*.cpp)

# compiles the files to generate the executable defined by TARGET
add_executable(${TARGET} ${SRCS})

# define any libraries to link into executable:
# For (libx.so or libx.a) use the -lx
# For (liby.so or liby.a) in ../lib use -ly
#target_link_libraries(${TARGET} x)
#target_link_libraries(${TARGET} y)
