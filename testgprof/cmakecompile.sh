#!/bin/bash

# Build commands
cd build
cmake ..
make

# Run executable
./main

# Get analysis of main
# the -b is to suppress verbose output
# the -p further limits to give only Flat profile i.e. no Call graph
gprof -b main gmon.out > analysis.txt
cat analysis.txt

# Remove generated executable etc.
make clean
rm -r *
cd ..

exit 0
