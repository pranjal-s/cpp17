/* -*- coding: utf-8; mode: c++; tab-width: 2; -*- -------------------------
   Implementation/definition file for User-Defined Types
------------------------------------------------------------------------- */
#include "udts.h"

Vector::Vector(int s)
{
  if (s<0)
    throw std::length_error{"Vector constructor: negative size"};
  elem = new double[s];
  sz = s;
}

void Vector::push_back(double d)
{
  sz +=1;
  double* elem2 = new double[sz];
  for (auto i=0; i<sz-1;++i)
    elem2[i] = elem[i];
  elem2[sz-1]=d;
  delete[] elem; // only derefrences the ptr
  elem = elem2;
}

double& Vector::operator[](int i) // if we add 'noexcept' here, error handling (try-catch) wouldn't be allowed
{
  if (i<0 || size()<=i)
    throw std::out_of_range{"Vector::operator[]"};
  return elem[i];
}

int Vector::size() const
{
  return sz;
}
