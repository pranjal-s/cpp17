/* ----------------------------------------------------------------------
   Interface/declaration file for User-Defined Types
------------------------------------------------------------------------- */
#ifndef UDTS_HPP
#define UDTS_HPP

struct Vector {
  // struct is basically a class with members public by default
  // data members
  int sz; // number of elements
  double* elem; // pointer to elements
}; // don't forget the semi-colon

// member functions declaration 'outside' the struct
void vector_init(Vector&, int);
int sum_sz(Vector, Vector&, Vector*);

// Classes are concepts introduced in C++ on top of C enabling encapsulation
// Encapsulation prevents people who work on your code from making mistakes,
// by making sure that they only access things they're supposed to access.
// Encapsulation is a process of combining data members and functions
// in a single unit called class.

class Vector2 {
  public: // member functions
    Vector2(int s):elem{new double[s]}, sz{s} { } // constructor with init
    // member functions definition 'inlines' inside the class (more efficient)
    double& operator[](int i) { return elem[i]; } // a getter cum setter
    int size() { return sz; } // getter
  private: // data members
    double* elem; // pointer to elements
    int sz; // number of elements
};

enum Type { ptr, num }; // a Type can hold values ptr and num
// Note that the enum is NOT strongly typed assuming no conflict of scope,
// but say we wanted to use num in "enum String { yum, num, dum };"
// Then, we need to use:
// enum class Type { ptr, num };
// to distinguish Type::num and String::num

// the Node class can instantiate a linked list
class Node {
  public:
	  double data;
	  Node* next;
};

// Union is like auto
union Value {
  Node* p;
  double n;
};

class Vector3 {
  public:
    Vector3(int s, Type x):elem{new Value[s]}, sz{s}, t{x} { }
    //double& operator[](int i) { return elem[i].n; }
    // works but doesn't allow using p which has return type Node*
    //Value& operator[](int i) { return (t==num)?elem[i].n:elem[i].p; }
    // doesn't work: return should be either Node* or double
    Value& operator[](int i) { return elem[i]; } // clean code
    int size() { return sz; }
    int type() { return t; }
  private:
    Type t;
    Value* elem; // Note: Should use elem.p if t==ptr; use elem.i if t==num
    int sz;
};

#endif
