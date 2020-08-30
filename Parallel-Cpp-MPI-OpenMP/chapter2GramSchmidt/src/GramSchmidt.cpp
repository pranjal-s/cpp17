/* -*- coding: utf-8; mode: c++; tab-width: 2; -*- -------------------------

   Implementation of Gram-Schmidt Vector Orthonormalization
     See ../README.md for details.
   Author: Pranjal Singh, pranjal.officemail@gmail.com, Sep 2020
   Source: https://github.com/pranjal-s/cpp17/blob/master/Parallel-Cpp-MPI-OpenMP/chapter2GramSchmidt/src/GramSchmidt.cpp

------------------------------------------------------------------------- */

#include "GramSchmidt.h"

// int GramSchmidt(size_t num_vec, size_t size_vec, void* x_void, void* q_void){
int GramSchmidt(size_t num_vec, size_t size_vec, double* x_void, double* q_void){
  // double (*x)[size_vec] = static_cast<double (*)[size_vec]>(x_void);
  // double (*q)[size_vec] = static_cast<double (*)[size_vec]>(q_void);
  double (&x)[num_vec][size_vec] = *reinterpret_cast<double (*)[num_vec][size_vec]>(x_void);
  double (&q)[num_vec][size_vec] = *reinterpret_cast<double (*)[num_vec][size_vec]>(q_void);

  double yj[size_vec];
  double r[num_vec][num_vec] = {0};
  
  for (size_t c = 0; c < size_vec; c++) r[0][0] += x[0][c]*x[0][c];
  r[0][0] = sqrt(r[0][0]);
  
  if(r[0][0]==0.0)
    return 1;
  else
    for (size_t c = 0; c < size_vec; c++) q[0][c] = x[0][c]/r[0][0];
    // cblas_daxpy(size_vec,1/r[0][0],x[0],1,q[0],1);

  for (size_t j = 1; j < num_vec; j++) {
    for (size_t i = 0; i < j; i++)
      for (size_t c = 0; c < size_vec; c++) r[i][j] += q[i][c]*x[j][c];
  
    // for (size_t c = 0; c < size_vec; c++) yj[c] = x[j][c];
  
    for (size_t i = 0; i < j; i++)
      for (size_t c = 0; c < size_vec; c++) yj[c] = x[j][c] - r[i][j]*q[i][c];
  
    for (size_t c = 0; c < size_vec; c++) r[j][j] += yj[c]*yj[c];
    r[j][j] = sqrt(r[j][j]);
  
    if(r[j][j] == 0.0)
      return 1;
    else
      for (size_t c = 0; c < size_vec; c++) q[j][c] = yj[c]/r[j][j];

  // std::cout << "RIJ: " << '\n';
  // for(int i=0;i<num_vec;i++){
  //   for(int c=0;c<num_vec;c++)
  //     std::cout << r[i][c] << ' ';
  //   std::cout << '\n';
  // }

  }

  return 0;
}

// int GramSchmidt(std::vector<std::vector<double>> x, std::vector<std::vector<double>> q){
//   int i,j;
//   int dim = x[0].size();
//   std::cout << dim << '\n';
//   std::vector<double> y(dim);
//   std::vector<std::vector<double>> r(dim, std::vector<double>(dim));
// 
//   r[0][0] = std::inner_product(x[0].begin(), x[0].end(), x[0].begin(), 0);
// 
//   if(r[0][0]==0.0)
//     return 1;
//   else
//     q[0] = x[0]*(1/r[0][0]);
// 
//   for(j=1;j<dim;j++){
//     for(i=0;i<=j-1;i++)
//       r[i][j] = std::inner_product(q[i].begin(), q[i].end(), x[j].begin(), 0)
// 
//     y = x[j];
//     for(i=0;i<=j-1;i++)
//       y = y - r[i][j]*q[i];
// 
//     r[j][j] = std::inner_product(y.begin(), y.end(), y.begin(), 0);
// 
//     if(r[j][j] == 0.0)
//       return 1;
//     else
//       q[j] = y*(1/r[j][j]);
//   }
// 
//   return 0;
// }