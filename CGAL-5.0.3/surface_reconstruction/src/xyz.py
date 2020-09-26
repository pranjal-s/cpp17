# -*- Mode: python; tab-width: 4; indent-tabs-mode:nil; coding:utf-8 -*-
# vim: tabstop=4 expandtab shiftwidth=4 softtabstop=4
#
# CGAL-5.0.3 Tutorial
# A simple program to read, visualize and write geometry files with Open3D
# for analysis with CGAL in C++
# Author: Pranjal Singh, pranjal.officemail@gmail.com, Aug 2020
# Source: https://github.com/pranjal-s/cpp17/blob/master/CGAL-5.0.3/open3d-0.9/xyzn.py
"""
CGAL Point Cloud Visualizer
========================================================

xyz files (positions) are produced by CGAL with write_xyz_points.

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
xyz = o3d.io.read_point_cloud("data/half.xyz", format='xyz')
print(xyz)
print("Test passed!")
print(np.asarray(xyz.points))
print("Visualizing point cloud ...")
print("Press 'n' to see normals and '+/-' to change size.")
o3d.visualization.draw_geometries([xyz])
print("Visualization works!")
quit()
