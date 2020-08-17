/* -*- c++ -*- ----------------------------------------------------------
   Interface/declaration file for User-Defined Types
------------------------------------------------------------------------- */
#ifndef UDTS_H
#define UDTS_H

#include <iostream>

/*
In the C and C++ programming languages, an inline function is one qualified with the keyword inline;
this serves two purposes. Firstly, it serves as a compiler directive that suggests (but does not require)
that the compiler substitute the body of the function inline by performing inline expansion,
i.e. by inserting the function code at the address of each function call,
thereby saving the overhead of a function call. (from https://en.wikipedia.org/wiki/Inline_function)

Functions defined in a class are inlined by default.
*/

class complex {
    double re, im; // representation: two doubles
  public:
    complex(double r, double i) :re{r}, im{i} {} // construct complex from two scalars
    complex(double r) :re{r}, im{0} {} // construct complex from one scalar
    complex() :re{0}, im{0} {} // default complex: {0,0}
    ~complex() {}

    // getter, setter overloading
    double real() const { return re; }
    void real(double d) { re=d; }
    double imag() const { return im; }
    void imag(double d) { im=d; }

    // this is still 'inline'
    complex& operator+=(complex z)
    {
    re+=z.re;
    im+=z.im;
    return *this;
    }
};

class Vector {
  public:
    Vector(int);
    ~Vector(){delete[] elem;} // since we use 'new', we must use delete (won't happen automatically)

    void push_back(double);

    double& operator[](int); // noexcept;
    int size() const;
  private:
    double* elem;
    int sz;
}; // The Vector is a 'container class': it creates objects that can have multiple elements at different times during run




#endif
