#!/bin/bash

# Build commands
cd build
cmake ..
make

# Run executable
./main

# Remove generated executable etc.
make clean
rm -r *
cd ..

exit 0
