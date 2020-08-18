# -*- Mode: python; tab-width: 4; indent-tabs-mode:nil; coding:utf-8 -*-
# vim: tabstop=4 expandtab shiftwidth=4 softtabstop=4
#
# CGAL-5.0.3 Tutorial
# A simple program to read, visualize and write xyzn point set with Open3D
# for analysis with CGAL in C++
# Source: Pranjal Singh, pranjal.officemail@gmail.com, Aug 2020
"""
CGAL Point Cloud Visualizer
========================================================

xyzn files (positions and normals) are produced by CGAL with write_xyz_points.

Open3D
-----------
Open3D is an open-source library that deals with 3D data.
The Open3D frontend exposes a set of carefully selected data structures
and algorithms in both C++ and Python. The backend is highly optimized
and is set up for parallelization.

Note
----

"""
import numpy as np
import open3d as o3d
print("Testing IO for point cloud ...")
xyzn = o3d.io.read_point_cloud("data/oni_CGAL.xyz", format='xyzn')
print(xyzn)
print("Test passed!")
o3d.io.write_point_cloud("data/oni_Open3D.xyz", xyzn)
print(np.asarray(xyzn.points))
print("Visualizing point cloud ...")
o3d.visualization.draw_geometries([xyzn])
print("Visualization works!")
quit()
