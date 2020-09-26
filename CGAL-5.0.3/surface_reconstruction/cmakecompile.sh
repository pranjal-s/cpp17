#!/bin/bash

# Build commands
cd build
cmake ..
make

# Run executable
cd ../src/
../build/main "data/atoms.xyz" $1

# Remove generated executable etc.
# read -p "Clean build? " -n 1 -r
# echo
# if [[ $REPLY =~ ^[Yy]$ ]]
# then
#   make clean
#   rm -r *
# fi

#cd ../build/
#make clean
#rm -r *

cd ..

exit 0
