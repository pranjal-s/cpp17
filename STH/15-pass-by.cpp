/* ----------------------------------------------------------------------
   #15: Pass by value, reference and pointer
------------------------------------------------------------------------- */

#include <iostream>

using namespace std;

// value
int pass1(int a) { // receive copy
  a = 2;
  cout << a;
  return a+1;
}

// reference
int pass2(int& a) { // receive address
  a = 2;
  cout << a;
  return a+1;
}

// const reference
int pass2b(const int& a) { // receive address
  // a = 2; // ERROR
  cout << a;
  return a+1;
}

// pointer
inline int pass3(int* a) { // recieve pointer
  *a = 2;
  cout << *a;
  return *a+1;
} // inlining overcomes overhead of moving to function declaration and back

int main() {
  int x = 3, y;
  y = pass1(x); // send name
  cout << x; // unchanged
  y = pass2(x); // send name
  cout << x; // changed
  y = pass2b(x); // send name
  cout << x; // unchanged
  y = pass3(&x); // send address
  cout << x; // changed
  return 0;
}
