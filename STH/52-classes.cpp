/* ----------------------------------------------------------------------
   #52: Classes and objects
------------------------------------------------------------------------- */

#include <iostream>

using namespace std;

class A {
public:
  int x;
  char y;
  // default constructor
  A(){
    x = 0;
    char = '0';
  }
  // parametrized constructor
  A(int x0, char y0) {
    x = x0;
    y = y0;
  }
  // copy constructor
  A(const &A a) {
    x = a.x;
    y = a.y;
  }
};

int main() {
  A a;
  A b(0,'0');
  A c = a;
  return 0;
}
