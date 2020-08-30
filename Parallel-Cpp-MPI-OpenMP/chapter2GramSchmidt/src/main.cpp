/* -*- coding: utf-8; mode: c++; tab-width: 2; -*- -------------------------

   Usage of GramSchmidt.* for Gram-Schmidt Vector Orthonormalization
   Author: Pranjal Singh, pranjal.officemail@gmail.com, Sep 2020
   Source: https://github.com/pranjal-s/cpp17/blob/master/Parallel-Cpp-MPI-OpenMP/chapter2GramSchmidt/src/GramSchmidt.cpp

------------------------------------------------------------------------- */

#include <iostream>
#include "GramSchmidt.h"

int main(int argc, char* argv[])
{
  // Ginen vector data
  double DX0[] = {1.0, 0.0, 2.0};
  double DX1[] = {2.0, 3.0, 0.0};

  // Create vec collection
  const size_t num_vec = 2;
  const size_t size_vec = 3;
  double x[num_vec][size_vec];
  for (size_t c = 0; c < size_vec; c++) {
    x[0][c] = DX0[c];
    x[1][c] = DX1[c];
  }

  // Compute orthonormalized vec collection
  double q[num_vec][size_vec] = {0};
  // int info = GramSchmidt(num_vec, size_vec, x, q);
  int info = GramSchmidt(num_vec, size_vec, &x[0][0], &q[0][0]);

  // Print original vecs
  std::cout << "Original vecs: " << '\n';
  for(int r=0;r<num_vec;r++){
    for(int c=0;c<size_vec;c++)
      std::cout << x[r][c] << ' ';
    std::cout << '\n';
  }

  // Print orthonormalized vecs
  std::cout << "Orthonormalized vecs: " << '\n';
  for(int r=0;r<num_vec;r++){
    for(int c=0;c<size_vec;c++)
      std::cout << q[r][c] << ' ';
    std::cout << '\n';
  }

  return 0;
}




// int main(int argc, char* argv[])
// {
//   // Ginen vector data
//   double DX0[] = {1.0, 0.0, 2.0};
//   double DX1[] = {2.0, 3.0, 0.0};
// 
//   // Create vec collection
//   // Preferring to use vec of vecs instead of arr of vecs
//   // num_vec is row, size_vec is col
//   int num_vec = 2;
//   int size_vec = 3;
//   std::vector<std::vector<double>> x(num_vec, std::vector<double>(size_vec));
//   std::copy(DX0 + 0, DX0 + sizeof(DX0)/sizeof(DX0[0]), x[0].begin());
//   std::copy(DX1 + 0, DX1 + sizeof(DX1)/sizeof(DX1[0]), x[1].begin());
// 
//   // Compute orthonormalized vec collection
//   std::vector<std::vector<double>> q(num_vec, std::vector<double>(size_vec)); 
//   int info = GramSchmidt(x,q);
// 
//   // Print orthonormalized vecs
//   for(int r=0;r<num_vec;r++){
//     for(int c=0;c<size_vec;c++)
//       std::cout << x[r][c] << ' ';
//     std::cout << '\n';
//   }
// 
//   return 0;
// }