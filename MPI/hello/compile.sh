#!/bin/bash

# Go to source directory
cd src

# For all cpp files, do all the compilation steps up to the production of object code, but don't link to produce an executable
mpic++ -std=c++11 -c main.cpp

# Link all object files together, along with the libraries, to produce the executable 'a'
mpic++ -std=c++11 -o ../a main.o

# Remove the object files
rm *.o

# Run executable
cd ..
mpirun -np 3 ./a

# Remove generated executable
rm a

exit 0
