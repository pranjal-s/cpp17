# testmake

Template for making C++ project. Ref: https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html

Make knows how to construct a program using a cpp file:
```bash
make hello
./hello
rm hello
```

For multiple files, it needs a `Makefile`:
```bash
make -f Makefile.1
./main
make -f Makefile.1 clean
```

By naming the makefile as `Makefile` we can simply do:
```bash
make
./main
make clean
```
