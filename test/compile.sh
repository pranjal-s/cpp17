#!/bin/bash

# For all cpp files in src, do all the compilation steps up to the production of object code, but dont link to produce an executable
g++ -c src/main.cpp

# Link all object files together, along with the libraries, to produce the executable 'a'
g++ -o a src/main.o

# Remove the object files
rm src/*.o

# Run executable
./a

# Remove generated executable
rm a

exit 0
