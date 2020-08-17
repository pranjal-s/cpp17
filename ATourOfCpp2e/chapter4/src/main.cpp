/* ----------------------------------------------------------------------
   A Tour of C++ (2nd Edition) by Bjarne Stroustrup
   Chapter 4: Classes
------------------------------------------------------------------------- */

#include <iostream>
#include "udts.h"

using namespace std;

int main()
{
  cout << "Hello World!" << endl;

  int s = 3;
  int s2 = 5;
  Vector v(s);
  double d;

  for (auto i=0; i!=s2; ++i) {
    std::cout << "Enter v["<< i <<"]:";
    if (i<s) {
    std::cin>>v[i]; // read into elements
    } else {
    std::cin>>d; // read into elements
    v.push_back(d);
    }
  }

  for (auto i=0; i!=s2; ++i)
    std::cout << v[i] << '\n';

  return 0;
}
