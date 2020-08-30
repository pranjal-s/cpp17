/* -*- coding: utf-8; mode: c++; tab-width: 2; -*- -------------------------
   Interface/declaration file for GramSchmidt.cpp
------------------------------------------------------------------------- */

#ifndef GRAMSCHMIDT_H
#define GRAMSCHMIDT_H

#include <vector>
#include <numeric>
#include <algorithm>
#include <cblas.h>
#include <lapacke.h>
#include <iostream>

// TO DO: Improve performance with CBLAS/LAPACKE for large size x
// std::vector<double> v;
// double* a = &v[0];

// int GramSchmidt(size_t, size_t, void*, void*);
int GramSchmidt(size_t, size_t, double*, double*);

// int GramSchmidt(std::vector<std::vector<double>>, std::vector<std::vector<double>>);

#endif