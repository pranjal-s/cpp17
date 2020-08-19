# testmake

Template for cmaking C++ project. Ref: http://www.cplusplus.com/articles/jTbCpfjN/

A Makefile is a native configuration file. `CMakeLists.txt` enables creation of platform-specific configuration file. With Make as native build system, the created configuration file would be a `Makefile`.

To build, run and clean the program, we can use `compile.sh`:
```bash
./compile.sh
```

It’s also possible to write a Makefile to use Make to conditionally compile the project, but it won’t be a simple task, because we’re dealing with files spread over multiple directories. This is the scenario where CMake really shines.

In fact, we would 'get' the Makefile using the CMakeLists.txt:
```bash
cd build
cmake ..
make
cat Makefile
```

To build, run and clean the program with CMake, we can use `cmakecompile.sh`:
```bash
./cmakecompile.sh
```

Installation:
```bash
sudo apt remove cmake
wget https://github.com/Kitware/CMake/releases/download/v3.18.1/cmake-3.18.1-Linux-x86_64.sh
sudo cp cmake-3.18.1-Linux-x86_64.sh /opt/
cd /opt/
chmod +x cmake-3.18.1-Linux-x86_64.sh
sudo bash cmake-3.18.1-Linux-x86_64.sh
y
y
sudo ln -s /opt/cmake-3.18.1-Linux-x86_64/bin/* /usr/local/bin/
cd ~
cmake --version
```
