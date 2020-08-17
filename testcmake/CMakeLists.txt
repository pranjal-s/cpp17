# This CMakeLists.txt only for cmake --version >= 3.5.1
cmake_minimum_required(VERSION 3.5.1)

# project name
project(testcmake)

# Compiler macro: g++ for C++
set(CMAKE_C_COMPILER "g++")

# compiler flags:
# set the C++11 standard
set(CMAKE_CXX_STANDARD 11)

# define any directories containing header files other than /usr/include:
include_directories(include)

# define library paths in addition to /usr/lib:
link_directories(lib)

# define any libraries to link into executable:
# For (libx.so or libx.a) use x
#target_link_libraries(x)

# define the C++ source files:
file(GLOB SRCS src/*.cpp)

# the build target executable:
set(TARGET main)

# compiles the files to generate the executable defined by TARGET
add_executable(${TARGET} ${SRCS})
