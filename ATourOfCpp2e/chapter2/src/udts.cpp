/* ----------------------------------------------------------------------
   Implementation/definition file for User-Defined Types
------------------------------------------------------------------------- */
#include "udts.h"

// member functions definition 'outside' the struct
void vector_init(Vector& v, int s)
{
  v.elem = new double[s]; // allocate an array of s doubles
  v.sz = s;
}

int sum_sz(Vector v, Vector& rv, Vector* pv)
{
  int i1 = v.sz; // access through name
  int i2 = rv.sz; // access through reference
  int i3 = pv->sz; // access through pointer
  return i1+i2+i3;
}
