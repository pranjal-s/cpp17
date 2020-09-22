#include "include.h"

void calc1(double x)
{
  double sum = 0;
  std::cout << "This is first calc" << std::endl;
  for (size_t i = 0; i < x; i++) sum += (x)/(x+1);
  std::cout << sum << std::endl;
	return;
}

void calc2(double x)
{
  double sum = 0;
  std::cout << "This is second calc" << std::endl;
  for (size_t i = 0; i < x; i++) sum += (x)/(x+1);
  std::cout << sum << std::endl;
	return;
}

