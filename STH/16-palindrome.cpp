/* ----------------------------------------------------------------------
   #16: Recursion example
------------------------------------------------------------------------- */

#include <iostream>

using namespace std;

int rev(int a, int b) {
  if (a==0) {
    return b;
  }
  int a2 = a%10;
  int a1 = (a-a2)/10;
  int b1 = b*10;
  return rev(a1,b1+a2);
}

int main() {
  int x = 33456541;
  cout << rev(x,0) << endl;
  return 0;
}
