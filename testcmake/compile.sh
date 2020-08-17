#!/bin/bash

# Build commands
g++ -o build/main src/include.cpp src/main.cpp -I./include -std=c++11

# Run executable
build/main

# Remove generated executable
rm build/main

exit 0
