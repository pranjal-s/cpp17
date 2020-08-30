/* ----------------------------------------------------------------------
   Parallel Scientific Computing in C++ and MPI
     by George Karniadakis and Robert M. Kirby
   Section 2.2.2: Binary Numbers and Round-off
     This section covers floating point arithmatic and machine precision
   Section 2.2.7: Basic Linear Algebra Subroutines - BLAS
     This section covers the BLAS library for numerical algebra
------------------------------------------------------------------------- */

#include <iostream>
#include <bitset>
#include <cblas.h>
#include <lapacke.h>

float FloatMachineEps(); // calculate machine epsilon at single precision
double DoubleMachineEps(); // calculate machine epsilon at double precision

int main(int argc, char* argv[])
{
  std::cout << "BEGIN SECTION 2.2.2: Binary Numbers and Round-off\n"
            << std::endl;

  std::cout << "Machine representation of any number is binary.\n"
               "It is called floating point representation.\n" << std::endl;
  int a = 126;
  short c = -315;

  std::bitset<8> x(a); // int is 1 byte (8 bits)
  std::bitset<16> y(c); // short (int) is 2 byte (16 bits)

  std::cout << "int " << a << " in binary is " << x << "\n";
  std::cout << "short " << c << " in binary is " << y << "\n";

  std::cout << "\nScientific notation has a sign (+/-), fraction "
               "(.123, 123 is the 'fraction' value) and an exponent "
               "(x10^3, 3 is the 'exponent' value).\n"
               "Single precision (float):  1,  8, 23 bits: 2^-126 to 2^128\n"
               "Double precision (double): 1, 11, 52 bits: 2^-1022 to 2^1024\n"
               "Double extended precision (long double): 128 bits\n"
            << std::endl;

  std::cout << "\nMachine epsilon: ep such that 1.0 + ep == 1.0\n"
               "Following are machine epsilon for my machine ...\n"
               "Single precision (float):  " << FloatMachineEps() << "\n"
               "Double precision (double):  " << DoubleMachineEps() << "\n"
            << std::endl;

  std::cout << "END SECTION 2.2.2\n" << std::endl;

  std::cout << "BEGIN SECTION 2.2.7: Basic Linear Algebra Subroutines - BLAS\n"
            << std::endl;

  // http://www.netlib.org/lapack/explore-html/d4/dd0/dscal_8f.html
  double DX[] = {1.0, 2.0, 3.0}; // (D)ouble array (X), dim: (1+(N-1)*abs(INCX))
  double DA = 4.323; // (D)ouble scalar (A)
  int N = 3; // integer (N)umber of elements in input vector(s)
  int INCX = 1; // storage spacing between elements of array DX
                // with INCX = 1, array DX represents a single vector
  cblas_dscal(N,DA,DX,INCX);
  std::cout << "cblas_dscal:" << "\n";
  for (size_t i = 0; i < N; i++) {
    std::cout << DX[i] << "\n";
  }

  // http://www.netlib.org/lapack/explore-html/d7/d2b/dgemm_8f.html
  int M = 5, K = 5;
  N = 5; // N is set separately than M, K because it was already declared
  double ALPHA = 1.0, BETA = 0.0;
  int LDA = K, LDB = N, LDC = N;
  double* A = new double[M*LDA];
  double* B = new double[LDA*LDB];
  double* C = new double[M*LDC];

  for (int i = 0; i < M*K; i++) A[i] = (double)(i+1);
  for (int i = 0; i < K*N; i++) B[i] = (double)(-i-1);
  for (int i = 0; i < M*N; i++) C[i] = 0.0;

  cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
              M, N, K, ALPHA, A, LDA, B, LDB, BETA, C, LDC);

  std::cout << "\ncblas_dgemm:" << "\n";
  std::cout << "A:";
  for (size_t i = 0; i < M*K; i++) {
    if (i%M == 0) std::cout << "\n";
    std::cout << A[i] << " ";
  }
  std::cout << "\nB:";
  for (size_t i = 0; i < K*N; i++) {
    if (i%K == 0) std::cout << "\n";
    std::cout << B[i] << " ";
  }
  std::cout << "\nC:";
  for (size_t i = 0; i < M*N; i++) {
    if (i%M == 0) std::cout << "\n";
    std::cout << C[i] << " ";
  }

  std::cout << "\n\nEND SECTION 2.2.7\n" << std::endl;


  std::cout << "BEGIN SECTION LAPACK: Linear Algebra PACKage - LAPACK\n"
            << std::endl;

  // http://www.netlib.org/lapack/explore-html/d8/d72/dgesv_8f.html
  const int N2 = 3, NRHS2 = 2, LDA2 = N2, LDB2 = N2;
  int ipiv[N2], info;
  double A2[LDA2*N2] = {
    +6.80, -2.11, +5.66,
    -6.05, -3.30, +5.36,
    -0.45, +2.58, -2.70
  };
  double B2[LDB2*NRHS2] = {
    +4.02, +6.19, -8.22,
    -1.56, +4.00, -8.67
  };

  info = LAPACKE_dgesv(LAPACK_COL_MAJOR, N2, NRHS2,
              A2, LDA2, ipiv, B2, LDB2);

  std::cout << "\nLAPACKE_dgesv:" << "\n";
  std::cout << "Solution \"x\":";
  for (size_t i = 0; i < LDB2*NRHS2; i++) {
    if (i%LDB2 == 0) std::cout << "\n";
    std::cout << B2[i] << " ";
  }
  std::cout << "\nDetails of LU factorization:";
  for (size_t i = 0; i < LDA2*N2; i++) {
    if (i%LDA2 == 0) std::cout << "\n";
    std::cout << A2[i] << " ";
  }
  std::cout << "\nPivot indices:";
  for (size_t i = 0; i < N2; i++) {
    std::cout << ipiv[i] << " ";
  }

  std::cout << "\n\nEND SECTION LAPACK" << std::endl;

  return 0;
}

float FloatMachineEps(){
  // For actual code, see: https://www.cambridge.org/core/books/parallel-scientific-computing-in-c-and-mpi/B9F38F023D507F1CCEB06ED755171FA9
  return 0;
}

double DoubleMachineEps(){
  // For actual code, see: https://www.cambridge.org/core/books/parallel-scientific-computing-in-c-and-mpi/B9F38F023D507F1CCEB06ED755171FA9
  return 0;
}
