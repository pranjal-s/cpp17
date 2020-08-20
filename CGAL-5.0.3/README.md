# CGAL 5.0.3
Notes and code snippets for the library [ The Computational Geometry Algorithms Library](https://doc.cgal.org/latest/Manual/packages.html).

Installation:
```bash
cd ~/
git clone https://github.com/CGAL/cgal.git CGAL-5.0.3
cd CGAL-5.0.3/
git checkout releases/CGAL-5.0.3
```

Dependencies:
```bash
sudo apt-get install libgmp-dev libmpfr-dev
sudo apt-get install libboost-all-dev
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
2. [3D Collection of Points](point_cloud_3D/) from [CGAL 5.0.3 - Package Overview/3D Point Set/](https://doc.cgal.org/latest/Point_set_3/index.html#Chapter_Point_Set_3)
3. [3D Surface Mesh](mesh_3D/) from [CGAL 5.0.3 - Package Overview/3D Surface Mesh Generation/](https://doc.cgal.org/latest/Surface_mesher/index.html#Chapter_3D_Surface_Mesh_Generation)
4. [Surface Mesh Recunstruction from Point Cloud with Normals](surface_reconstruction/) from [CGAL 5.0.3 - Package Overview/Advancing Front Surface Reconstruction/](https://doc.cgal.org/latest/Advancing_front_surface_reconstruction/index.html#Chapter_Advancing_Front_Surface_Reconstruction). Also see [Ball Pivoting Algorithm](https://github.com/rodschulz/BPA) which can be more efficient.
