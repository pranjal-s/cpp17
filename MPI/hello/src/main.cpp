/* ----------------------------------------------------------------------
   MPI hello world program
     A simple parallel program for each process to print independently
   Author: Pranjal Singh, pranjal.officemail@gmail.com, Aug 2020
   Source: https://github.com/pranjal-s/cpp17/blob/master/MPI/hello/src/main.cpp
------------------------------------------------------------------------- */

#include <iostream>
#include <mpi.h>

int main(int argc, char* argv[])
{
  std::cout << "BEGIN PROGRAM (MISPLACED)\n" << std::endl;
  // The nesting of BEGIN and END shows that MPI runs entire program in a
  // distributed manner. The nesting is artifact of 'misuse' of an MPIC++
  // (distributed parallelization) program.
  // To do it properly, put thebounds inside MPI_Init and MPI_Finalize

  int numtasks, rank, len;
  char hostname[MPI_MAX_PROCESSOR_NAME];
  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD,&numtasks);
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  MPI_Get_processor_name(hostname, &len);

  std::cout << "BEGIN MPI PROGRAM" << std::endl;

  std::cout << "Hello World!" << std::endl;
  std::cout << "Number of tasks = " << numtasks
            << ", My rank = " << rank
            << ", Running on host = " << hostname << "\n";

  std::cout << "END MPI PROGRAM\n" << std::endl;

  MPI_Finalize();

  std::cout << "\nEND PROGRAM (MISPLACED)" << std::endl;

  return 0;
}
