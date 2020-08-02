// An example of using static for modifying return-by-reference
// and const for blocking such modification

#include <iostream>

using namespace std;

int& f(int& x)
{
  static int *z = new int;
  *z = x + 1;
  return *z;
}

const int& g(int& x)
{
  static int *z2 = new int;
  *z2 = x + 1;
  return *z2;
}

int main()
{
     cout << "Hello World!" << endl;
     int x = 2;
     int& y = f(x);
     f(x) = 4;
     cout << "Returned value = " << y << endl;
     const int& y2 = g(x);
     // g(x) = 4; // throws error because we've blocked return of g(x) from assignment
     cout << "Returned value = " << y2 << endl;
     return 0;
}


/* Notes on pointer and references, from: https://stackoverflow.com/questions/2837241/c-returning-pointers-references
Although Peter answered your question, one thing that's clearly confusing you is the symbols * and &. The tough part about getting your head around these is that they both have two different meanings that have to do with indirection (even excluding the third meanings of * for multiplication and & for bitwise-and).

*, when used as part of a type indicates that the type is a pointer: int is a type, so int* is a pointer-to-int type, and int** is a pointer-to-pointer-to-int type.

& when used as part of a type indicates that the type is a reference. int is a type, so int& is a reference-to-int (there is no such thing as reference-to-reference). References and pointers are used for similar things, but they are quite different and not interchangable. A reference is best thought of as an alias, or alternate name, for an existing variable. If x is an int, then you can simply assign int& y = x to create a new name y for x. Afterwords, x and y can be used interchangeably to refer to the same integer. The two main implications of this are that references cannot be NULL (since there must be an original variable to reference), and that you don't need to use any special operator to get at the original value (because it's just an alternate name, not a pointer). References can also not be reassigned.

* when used as a unary operator performs an operation called dereference (which has nothing to do with reference types!). This operation is only meaningful on pointers. When you dereference a pointer, you get back what it points to. So, if p is a pointer-to-int, *p is the int being pointed to.

& when used as a unary operator performs an operation called address-of. That's pretty self-explanatory; if x is a variable, then &x is the address of x. The address of a variable can be assigned to a pointer to the type of that variable. So, if x is an int, then &x can be assigned to a pointer of type int*, and that pointer will point to x. E.g. if you assign int* p = &x, then *p can be used to retrieve the value of x.

So remember, the type suffix & is for references, and has nothing to do with the unary operatory &, which has to do with getting addresses for use with pointers. The two uses are completely unrelated. And * as a type suffix declares a pointer, while * as a unary operator performs an action on pointers.


int* returnA() {
    int *j = &a;
    return j;
}

int* returnB() {
    return &b;
}

int& returnC() {
    return c;
}

int& returnC2() {
    int *d = &c;
    return *d;
}

*/
