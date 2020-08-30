# Chapter 2.2: Mathematical and computational concepts

## 2.2.6: Memory layout for matrices and cache blocking

**Memory layout for matrices**: The memory is a one-dimensional partitioned
strip with addresses. Since memory is linearly addressable, in order to store a
two-dimensional array we must decide how to decompose the matrix into
one-dimensional units. C++ uses row-major ordering while FORTRAN uses
column-major ordering.

**Cache blocking**:  Main memory is normally much slower than the CPU. Items
from main memory are loaded in blocks of size equal to the size of a `cache
line`, a term which comes from the size of the lines going from main memory
modules to the cache memory modules. By choosing to store the matrix A in
row-major order for the MatVec.ij algorithm helps maximize `cache hits` to
`cache miss` ratio.

Hence, efficiency of algorithm depends on memory layout of the data structure.

## 2.2.7: [Basic Linear Algebra Subroutine - BLAS](http://www.netlib.org/blas/)
Typical BLAS routines are divided into 3 levels:
+ BLAS1: O(n<sup>1</sup>) e.g. inner dot product, `sdot`, scalar alpha x plus y `saxpy`
+ BLAS2: O(n<sup>2</sup>) e.g. matrix-vector multiplication, `sgemv`
+ BLAS3: O(n<sup>3</sup>) e.g. matrix-vector multiplication, `sgemm`

They apply to 4 data prefixes i.e. S, D, C and Z:
+ (S)INGLE: single precision e.g. `Saxpy`, `sgemv`, `sgemm`
+ (D)OUBLE: double precision e.g. `Daxpy`, `dgemv`, `dgemm`
+ (C)OMPLEX: single complex e.g. `Caxpy`, `cgemv`, `cgemm`
+ (Z) COMPLEX*16 or DOUBLE COMPLEX: double complex e.g. `Zaxpy`, `zgemv`, `zgemm`

And several types of matrices:
+ (GE) General (i.e., unsymmetric, in some cases rectangular) e.g. `sGEmm`
+ (HY) Hermetian
+ (SY) Symmetric
+ (TR) Triangular
+ (GB) General Banded
...
...

For more, see: [Naming Scheme](https://www.netlib.org/lapack/lug/node24.html)

For C/C++, each function name must be followed by `cblas_` e.g. `cblas_sgemv`. See: [Calling BLAS Functions that Return the Complex Values in C/C++ Code](https://software.intel.com/content/www/us/en/develop/documentation/mkl-macos-developer-guide/top/language-specific-usage-options/mixed-language-programming-with-the-intel-math-kernel-library/calling-blas-functions-that-return-the-complex-values-in-c-c-code.html)

Installation:
```bash
sudo apt-get install libblas-dev
# Then add -lblas to compiler
# And use #include<cblas.h>
```

## LAPACK: Linear Algebra PACKage - LAPACK
BLAS is a collection of low-level matrix and vector arithmetic operations (“multiply a vector by a scalar”, “multiply two matrices and add to a third matrix”, etc ...).

LAPACK is a collection of higher-level linear algebra operations. Things like matrix factorizations (LU, LLt, QR, SVD, Schur, etc) that are used to do things like “find the eigenvalues of a matrix”, or “find the singular values of a matrix”, or “solve a linear system”. LAPACK is built on top of the BLAS; many users of LAPACK only use the LAPACK interfaces and never need to be aware of the BLAS at all. LAPACK is generally compiled separately from the BLAS, and can use whatever highly-optimized BLAS implementation you have available.

Installation:
```bash
sudo apt-get install liblapacke-dev
# Then add -llapacke to compiler
# And use #include<lapacke.h>
```
