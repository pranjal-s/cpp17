#!/bin/bash

# Build commands
g++ -std=c++11 -o build/main src/include.cpp src/main.cpp -I./include

# Run executable
build/main

# Remove generated executable
rm build/main

exit 0
