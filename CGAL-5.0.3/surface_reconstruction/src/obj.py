# -*- Mode: python; tab-width: 4; indent-tabs-mode:nil; coding:utf-8 -*-
# vim: tabstop=4 expandtab shiftwidth=4 softtabstop=4
#
# CGAL-5.0.3 Tutorial
# A simple program to convert off file to obj with meshconv.exe
# for analysis with CGAL in C++
# Author: Pranjal Singh, pranjal.officemail@gmail.com, Aug 2020
# Source: https://github.com/pranjal-s/cpp17/blob/master/CGAL-5.0.3/surface_reconstruction/src/obj.py
"""
CGAL Mesh OFF to OBJ conversion
========================================================

OBJ file is produced from CGAL OFF file for visualization with OVITO.

Note
----

"""

import os
import subprocess
os.chdir("data")
filename = "atoms_CGAL.off"
args = "meshconv.exe " + filename + " -c obj"
subprocess.call(args, shell=False),
os.chdir("..")
quit()
