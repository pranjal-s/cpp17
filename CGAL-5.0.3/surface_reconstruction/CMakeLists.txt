# This CMakeLists.txt only for cmake --version >= 3.5.1, here I have 3.16.3
cmake_minimum_required(VERSION 3.5.1)

# project name
project(surface_reconstruction)

# Build Type Release for high optimization and no debugging
set(CMAKE_BUILD_TYPE Release)

# Compiler macro: Minimum v6.3, here I have v9.3
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

# compiler flags:
# set the minimum required C++14 standard
set(CMAKE_CXX_STANDARD 14)

# the build target executable:
set(TARGET main)

# executable working directory
#target_compile_definitions(${TARGET} PUBLIC -DPROJECT_DIRECTORY="${CMAKE_SOURCE_DIR}")
# If want to use this trick, SEE: https://stackoverflow.com/questions/38451654/clion-c-cant-read-open-plain-file-in-project-directory
# then. you can run ./main instead of cd ../src/; ../build/main

# define any directories containing header files other than /usr/include:
include_directories(include)
set(CGAL_DIR ~/CGAL-5.0.3)

# define library paths in addition to /usr/lib:
link_directories(lib)

# CGAL and its components
find_package( CGAL QUIET COMPONENTS  )
if ( NOT CGAL_FOUND )
  message(STATUS "This project requires the CGAL library, and will not be compiled.")
  return()
endif()

# Boost and its components
find_package( Boost REQUIRED )
if ( NOT Boost_FOUND )
  message(STATUS "This project requires the Boost library, and will not be compiled.")
  return()
endif()


# define the C++ source files:
file(GLOB SRCS src/*.cpp)

# compiles the files to generate the executable defined by TARGET
add_executable(${TARGET} ${SRCS})

# define any libraries to link into executable:
# For (libx.so or libx.a) use the -lx
# For (liby.so or liby.a) in ../lib use -ly
#target_link_libraries(${TARGET} x)
#target_link_libraries(${TARGET} y)

# Link the executable to CGAL and third-party libraries
#add_to_cached_list( CGAL_EXECUTABLE_TARGETS ${TARGET} )
target_link_libraries(${TARGET} PRIVATE CGAL::CGAL )
