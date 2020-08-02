#!/bin/bash

# Remove if present previously generated executable
rm -f a

# Go to source directory
cd src

# For all cpp files, do all the compilation steps up to the production of object code, but don't link to produce an executable
g++-7 -std=c++17 -c main.cpp udts.cpp udts2.cpp

# Link all object files together, along with the libraries, to produce the executable 'a'
g++-7 -std=c++17 -o ../a main.o udts.o udts2.o

# Remove the object files
rm *.o

# Run executable
cd ..
./a

exit 0
