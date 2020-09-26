# surface_reconstruction

Read, write and visualize surface reconstruction of atoms.xyz in src/data:
```bash
# Run CGAL Advancing_front_surface_reconstruction
./cmakecompile.sh 0
# the bash script argument is parameter to avoid closing of the open surface
# set it to 0.4 if open surface wanted in case of half.xyz
# for the default surf recon of atoms.xyz the parameter makes no difference

# Convert CGAL surface mesh (off) to CGAL surface mesh (obj)
### NOTE: THE SCRIPT meshconv.exe IS NOT WRITTEN BY ME. THIS IS THE SOURCE: https://www.patrickmin.com/meshconv/
cd src
python obj.py # if using ovito
python main.py # if using open-3d
```
