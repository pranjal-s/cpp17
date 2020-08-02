/* -*- c++ -*- ----------------------------------------------------------
   Interface/declaration file for User-Defined Types
------------------------------------------------------------------------- */
#ifndef UDTS_H
#define UDTS_H

#include <iostream>
#include <map>

double square(double); // square a double precision floating-point number

class Vector {
  public:
    Vector(int);
    double& operator[](int); // noexcept;
    Vector square();
    int size();
  private:
    double* elem;
    int sz;
}; // The Vector class creates an object that can have multiple elements at different times during program execution

// Multiple data types in a single structure
struct Entry {
  std::string name;
  int value;
};

Entry read_entry(std::istream&); // read entries from input stream

void incr(std::map<std::string,int>&); // increment the value of each element of m

#endif
