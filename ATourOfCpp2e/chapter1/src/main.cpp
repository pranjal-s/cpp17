/* ----------------------------------------------------------------------
   A Tour of C++ (2nd Edition) by Bjarne Stroustrup
   Chapter 1: Basics.
------------------------------------------------------------------------- */

// Includes
#include <iostream>
#include <cmath>
#include <complex>
#include <vector>

// Namespaces
using namespace std;

// Function declarations
double square(double); // square a double precision floating-point number
void print_square(double); // use square and print the square
int count_x(const char*, char); // count the number of occurrences of x in p[];
// p is assumed to point to a zero-terminated array of char (or to nothing)

// Function definitions
double square(double x) {
  return x*x;
}

void print_square(double x) {
  cout << "the square of " << x << " is " << square(x) << "\n";
}

constexpr double ce_square(double x) {
  return x*x;
}

int count_x(const char* p, char x) {
  if (p==nullptr) // less ambigous than p==NULL
    return 0;
  int count = 0;
  while (*p) // while the end (which points to nullptr) has not been reached
    if (*p==x)
      ++count;
    ++p;
  return count;
}

// Driver
int main(int argc, char* argv[]) {
  cout << "Hello World!" << endl;
  print_square(1.234);

  double d1 = 2.7; // initialize d0 to 2.3 using assignment (NOT PREFERRED)
  double d2 {2.7}; // initialize d2 to 2.3 using constructor
  double d3 = {2.7}; // initialize d3 to 2.3 using constructor
  int d4 = d1; // NOT PREFERRED, since 'narrowing conversion' would happen
  int d5{d1}; // it also happens with constructor
  int d6{round(d1)}; // best-practice to round off unless type of d1 is insured
  printf("%i %i %i\n", d4, d5, d6);

  complex<double> z = 1; // a complex number with double-precn float-pt scalars
  complex<double> z2 {d1,d2};
  complex<double> z3 = {d1,d2}; // the = is optional with { ... }
  vector<int> v0 {1,2,3,4,5,6}; // a vector of ints

  // Constants and Constexpr
  const int dmv0 = 17; // dmv0 is immutable and evaluated at RUN/COMPILE time
  constexpr int dmv = 17; // dmv is also immutable but evaluates at COMPILE
  double sum(const vector<double>&); // arg modification not allowed
  int var = 17; // var is not a constant
  const double sqv = sqrt(var); // sqv is a named const, maybe computed at run
  constexpr double max1 = 1.4*ce_square(17); // OK: 17 is a constant
  // constexpr double max2 = 1.4*ce_square(var); // ERROR
  // the value of ‘var’ is not 'usable' in a constant expression
  const double max3 = 1.4*ce_square(var); // OK: may be evaluated at run time

  // Array and pointer declaration
  char v[6] = {0,1,2,3,4,5}; // [] = 'array of'
  char* p; // * = pointer to
  
  // Array and pointer expression
  p = &v[3]; // &= address of; p points to v’s fourth element
  char x = *p; // *= contents of; *p is the object that p points to,
  // that object is of type char and is being assigned to x

  // Aliasing
  int xx = 2;
  int yy = 33;
  int& r = xx; // r refers to xx
  int& r2 = yy; // now r2 refers to yy
  r = r2; // yy read through r2, x written through r: xx becomes 33
  cout << xx << '\n';

  // Array is contiguous
  int v1[10] = {0,1,2,3,4,5,6,7,8,9};
  int* vptr = v1; // vptr points to beginning of array v1
  for (int i = 0; i < 10; ++i) {
    cout << *(vptr+i) << " "; // increment pointer
  }
  cout << endl;

  // Copy
  int v2[10]; // can't just have v2[]
  for (auto i=0; i!=10; ++i) // auto infers type from the assigned value
    v2[i]=v1[i];

  for (auto x:v1) // range-for-statement
    cout << x << '\n';

  for (auto& x : v2) // using &, we can add 1 to each x in v directly
    ++x;

  for (auto x:v1)
    cout << x << '\n';

  return 0;
}
