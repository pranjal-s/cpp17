# CGAL 5.0.3
Notes and code snippets for the library [ The Computational Geometry Algorithms Library](https://doc.cgal.org/latest/Manual/packages.html).

Installation:
```bash
cd ~/
git clone https://github.com/CGAL/cgal.git CGAL-5.0.3
cd CGAL-5.0.3/
git checkout releases/CGAL-5.0.3
```

Verify installation:
```bash
cd ~/CGAL-5.0.3/
cd Kernel_23/examples/Kernel_23/
mkdir -p build/debug
cd build/debug
cmake -DCMAKE_BUILD_TYPE=Debug -DCGAL_DIR=~/CGAL-5.0.3/ ../..
make
ls
./points_and_segment
```

Verify use in external code (using same example file with a CMake project in this directory):
```bash
cd points_and_segments/
./cmakecompile.sh
```

Index:
1. [Three Points and One Segment Example](points_and_segments/) from [CGAL 5.0.3 - Manual/Tutorials/](https://doc.cgal.org/latest/Manual/tutorial_hello_world.html)
2. [The Convex Hull of a Sequence of Points](array_convex_hull_2/) from [CGAL 5.0.3 - Manual/Tutorials/](https://doc.cgal.org/latest/Manual/tutorial_hello_world.html)
