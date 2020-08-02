/* -*- c++ -*- ----------------------------------------------------------
   Interface/declaration file for User-Defined Types
------------------------------------------------------------------------- */
#ifndef UDTS_H
#define UDTS_H

struct Vector {
  // struct is basically a class with members public by default
  // data members
  int sz; // number of elements
  double* elem; // pointer to elements
}; // don't forget the semi-colon

// member functions declaration 'outside' the struct
void vector_init(Vector&, int);
int sum_sz(Vector, Vector&, Vector*);

class Vector2 {
  public: // member functions
    Vector2(int s):elem{new double[s]}, sz{s} { } // constructor with initialization (vector_init)
    // member functions definition 'inline' inside the class (more efficient)
    double& operator[](int i) { return elem[i]; } // a getter (that ALLLOWS use as setter)
    int size() { return sz; } // getter
  private: // data members
    double* elem; // pointer to elements
    int sz; // number of elements
};

// Here, we enable Vector3 to instantiate vector of doubles as well as vector of Node pointers

// We use the enum Type for the enumeration of type fields for the vector3
// Note that the enum is NOT strongly typed assuming no conflict of scope,
// but say we wanted to use num in "enum String { yum, num, dum };" Then, we need to use:
// enum class Type { ptr, num }; so we can distinguish Type::num and String::num
enum Type { ptr, num }; // a Type can hold values ptr and num

// We use the Node class for instantiating a linked list of 3 elements in the main
class Node {
  public:
	  double data;
	  Node* next;
};

// Union helps organize the idea that some value might have different types
union Value {
  Node* p;
  double i;
};

class Vector3 {
  public:
    Vector3(int s, Type x):elem{new Value[s]}, sz{s}, t{x} { }
    //double& operator[](int i) { return elem[i].i; } // works but doesn't allow using p which has return type Node*
    //Value& operator[](int i) { return (t==num)?elem[i].i:elem[i].i; } // doesn't work: return should be either Node* or double
    Value& operator[](int i) { return elem[i]; }
    int size() { return sz; }
    int type() { return t; }
  private:
    Type t;
    Value* elem; // use elem.p if t==ptr; use elem.i if t==num
    int sz;
};

/*
class Vector4 {
  public:
    Vector4(int s, Type x):elem{new Value[s]}, sz{s}, t{x} { }
    auto& operator[](int);
    int size() { return sz; }
    int type() { return t; }
  private:
    Type t;
    Value* elem; // use elem.p if t==ptr; use elem.i if t==num
    int sz;
};
*/

#endif
