#!/bin/bash

# Go to source directory
cd src

# For all cpp files, do all the compilation steps up to the production of object code, but dont link to produce an executable
g++ -c main.cpp

# Link all object files together, along with the libraries, to produce the executable 'a'
g++ -o ../a main.o

# Remove the object files
rm *.o

# Run executable
cd ..
./a

# Remove generated executable
rm -f a

exit 0
