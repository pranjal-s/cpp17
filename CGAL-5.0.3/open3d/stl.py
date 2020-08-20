# -*- Mode: python; tab-width: 4; indent-tabs-mode:nil; coding:utf-8 -*-
# vim: tabstop=4 expandtab shiftwidth=4 softtabstop=4
#
# CGAL-5.0.3 Tutorial
# A simple program to read, visualize and write geometry files with Open3D
# for analysis with CGAL in C++
# Author: Pranjal Singh, pranjal.officemail@gmail.com, Aug 2020
# Source: https://github.com/pranjal-s/cpp17/blob/master/CGAL-5.0.3/open3d-0.9/stl.py
"""
CGAL STL Mesh Visualizer
========================================================

stl files are produced by CGAL with the STL format.

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
print("Testing IO for CGAL STL mesh ...")
stlmesh = o3d.io.read_triangle_mesh("data/half_CGAL.stl")
print(stlmesh)
print("Test passed!")
print("Converting to Open3D OFF mesh ...")
o3d.io.write_triangle_mesh("data/half_Open3D.off", stlmesh)
print(stlmesh)
print('Vertices:')
print(np.asarray(stlmesh.vertices))
print('Triangles:')
print(np.asarray(stlmesh.triangles))

print("Visualizing mesh ...")
print("Press 'w' to see wireframe (mesh) and 'b' to switch back and front.")
print("Try to render a mesh with normals (exist: " +
        str(stlmesh.has_vertex_normals()) + ") and colors (exist: " +
        str(stlmesh.has_vertex_colors()) + ")")
o3d.visualization.draw_geometries([stlmesh])
print("Visualization works!")
quit()
