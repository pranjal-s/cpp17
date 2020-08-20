# Open3D-0.9

Installation:
```bash
conda activate mdanalysis-dev
conda update -n base -c defaults conda
conda update --all
conda install -c open3d-admin open3d=0.9
# I use v0.9 because I don't have GLIBC_2.27 on Ubuntu 16.04
```

Verify installation:
```bash
python -c "import open3d as o3d;print(o3d.__version__)"
```
