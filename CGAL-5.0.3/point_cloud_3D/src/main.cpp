// A simple program to read and write xyzn point set with CGAL
// for visualization with Open3D in python
// Source: https://doc.cgal.org/latest/Point_set_processing_3/index.html#Point_set_processing_3Example_io

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/property_map.h>
#include <CGAL/IO/read_xyz_points.h>
#include <CGAL/IO/write_xyz_points.h>
#include <utility> // defines std::pair
#include <vector>
#include <fstream>
#include <iostream>
// types
typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;
typedef Kernel::Point_3 Point;
typedef Kernel::Vector_3 Vector;
// Point with normal vector stored as a std::pair.
typedef std::pair<Point, Vector> Pwn;
int main(int argc, char*argv[])
{
  const char* fname = (argc>1)?argv[1]:"data/oni.xyz";
    // Reads a .xyz point set file in points[].
    // Note: read_xyz_points() requires an output iterator
    // over points and as well as property maps to access each
    // point position and normal.
    std::vector<Pwn> points;
    std::ifstream in(fname);
    if (!in ||
        !CGAL::read_xyz_points(
            in,std::back_inserter(points),
            CGAL::parameters::point_map (CGAL::First_of_pair_property_map<Pwn>()).
            normal_map (CGAL::Second_of_pair_property_map<Pwn>())))
    {
      std::cerr << "Error: cannot read file " << fname << std::endl;
      return EXIT_FAILURE;
    }
    // Saves point set.
    // Note: write_xyz_points() requires property maps to access each
    // point position and normal.
    std::ofstream out("data/oni_CGAL.xyz");
    out.precision(17);
    if (!out ||
        !CGAL::write_xyz_points(
          out, points,
          CGAL::parameters::point_map(CGAL::First_of_pair_property_map<Pwn>()).
          normal_map(CGAL::Second_of_pair_property_map<Pwn>())))
    {
      return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
