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

int sum_sz(Vector v, Vector& rv, Vector* pv) // while we can do the same thing in 3 different ways,
// 1st is costly because it copies
// 2nd is best if you don't want to modify and want to achieve this without making a copy to work with
// note that arguments passed-by-reference create 'temporaries' (that which would only exist for use in calculations i.e. as rvalue)
// hence, pass-by-reference automatically implies const
// 3rd is best if you want to modify vector pv
{
  int i1 = v.sz; // access through name
  int i2 = rv.sz; // access through reference
  int i3 = pv->sz; // access through pointer
  return i1+i2+i3;
}

/*
auto& Vector4::operator[](int i)
{
  if (t==num)
    return elem[i].i;
  if (t==ptr)
    return elem[i].p;
}
*/
