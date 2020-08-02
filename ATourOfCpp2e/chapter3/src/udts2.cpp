/* ----------------------------------------------------------------------
   Implementation/definition file for User-Defined Types
------------------------------------------------------------------------- */
#include "udts2.h"

int pranjal::main()
{
  Vector z(2);
  z[0] = 1; z[1] = 2;
  auto z2 = z.square();
  std::cout << '{' << z2[0] << ',' << z2[1] << "}\n";
  std::cout << "This worked!\n";
}
