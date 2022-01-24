/* ----------------------------------------------------------------------
   #13: Returning array out of a function
------------------------------------------------------------------------- */

#include <iostream>
#include <string>

using namespace std;

// method 1: declare static
int* returnArray1() {
  static int arr[3];
  arr[0]=1;
  arr[1]=2;
  arr[2]=3;
  return arr;
}

// method 2: dynamically allocate (on heap)
int* returnArray2() {
  int* arr = new int[3];
  arr[0]=1;
  arr[1]=2;
  arr[2]=3;
  return arr;
}

int main() {
  int* aryPtr1 = returnArray1();
  int* aryPtr2 = returnArray2();
  return 0;
}
