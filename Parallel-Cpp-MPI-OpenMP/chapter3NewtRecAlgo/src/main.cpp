/* -*- coding: utf-8; mode: c++; tab-width: 2; -*- -------------------------

   1D Polynomial approximation of arbitrary function with Newton Recursive Algorithm
   Author: Pranjal Singh, pranjal.officemail@gmail.com, Sep 2020
   Source: https://github.com/pranjal-s/cpp17/blob/master/Parallel-Cpp-MPI-OpenMP/chapter2GramSchmidt/src/.cpp

------------------------------------------------------------------------- */

#include <iostream>
#include <vector>
#include <fstream>

double function(double x);
double function_newton(double x, double* xi, double* yi, double N);
double basis_phi(double x, double* xi, int k);
double get_ak(double* xi, double* yi, int j, int k);
std::vector<double> LinearSpacedArray(double a, double b, size_t N);

int main(int argc, char* argv[])
{
  int N = 10;
  double a=-1.0, b=1.0;
  std::vector<double> xs = LinearSpacedArray(a, b, N+1);
  double* xi = &xs[0];

  double yi[N+1];
  for (size_t i = 0; i < N+1; i++) yi[i] = function(xi[i]);
  int npts = 1000;
  std::vector<double> xpts = LinearSpacedArray(a, b, npts);
  double* xpti = &xpts[0];
  
  std::ofstream outfile("plt.dat");
  outfile << "# Output from fix savevolume" << '\n';
  outfile << "# x function function_newton" << '\n';
  for (size_t i = 0; i < npts; i++) {
    outfile << xpti[i] << " " << function(xpti[i]) << " " << function_newton(xpti[i], xi, yi, N) << '\n';
  }
  outfile.close();

  return 0;
}

double function(double x)
{
  return 1.0/(1.0 + 25.0*x*x);
}

double function_newton(double x, double* xi, double* yi, double N)
{
  double sum = 0;
  double ak;
  for (size_t k = 0; k < N+1; k++) {
    ak = get_ak(xi,yi,0,k);
    sum += ak*basis_phi(x, xi, k);
  }
  return sum;
}

double basis_phi(double x, double* xi, int k)
{
  double mul = 1;
  for (size_t i = 0; i < k; i++) mul *= (x - xi[i]);
  return mul;
}

double get_ak(double* xi, double* yi, int j, int k)
{
  if (j==k) return yi[k];
  return (get_ak(xi,yi,j,k-1)-get_ak(xi,yi,j+1,k))/(xi[j]-xi[k]);
}

// Linear interpolation following MATLAB linspace
// Source: https://gist.github.com/mortenpi/f20a93c8ed3ee7785e65
std::vector<double> LinearSpacedArray(double a, double b, size_t N)
{
  double h = (b - a) / static_cast<double>(N-1);
  std::vector<double> xs(N);
  std::vector<double>::iterator x;
  double val;
  for (x = xs.begin(), val = a; x != xs.end(); ++x, val += h) {
    *x = val;
  }
  return xs;
}