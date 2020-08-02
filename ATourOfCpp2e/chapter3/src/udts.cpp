/* ----------------------------------------------------------------------
   Implementation/definition file for User-Defined Types
------------------------------------------------------------------------- */
#include "udts.h"

double square(double x) // TODO: variable arguments
{
  return x*x;
}

/*
// Without error handling
Vector::Vector(int s):
  elem{new double[s]}, sz{s}
{

}
*/

Vector::Vector(int s)
{
  if (s<0)
    throw std::length_error{"Vector constructor: negative size"};
  elem = new double[s];
  sz = s;
}

double& Vector::operator[](int i) // if we add 'noexcept' here, error handling (try-catch) wouldn't be allowed
{
  if (i<0 || size()<=i)
    throw std::out_of_range{"Vector::operator[]"};
  return elem[i];
}

int Vector::size()
{
  return sz;
}

// When you return an object by-value, the copy-constructor is called, and a temporary instance is created on the stack.
// When you return an object by-reference, all the above does not take place, leading to improved performance.
// When you return an object by-const-reference, assignment to returned object is not allowed.
// This DOESN'T mean the derefrenced object is const, just that it ca
Vector Vector::square()
{
  int s = this->sz;
  Vector v(s);
  for (auto i=0;i<s;++i) {
    v[i] = this->elem[i] * this->elem[i];
    //std::cout << v[i] << '\n';
  }
  return v;
}

// A function that returns a composite object
Entry read_entry(std::istream& is)
{
  std::string s;
  int i;
  std::cout << "String entry: ";
  is >> s;
  std::cout << "Integer entry: ";
  is >> i;
  return {s,i};
}

void incr(std::map<std::string,int>& m)
{
  for (auto& [key,value] : m)
    ++value;
}
