/* ----------------------------------------------------------------------
   Cracking the Coding interview (6th Edition) by G. L. McDowell
   VII: STL Containers - adaptors.
   Coding Ref: https://www.geeksforgeeks.org/containers-cpp-stl/
------------------------------------------------------------------------- */

// Includes
#include <iostream>
#include <vector>
#include <deque>

#include <stack> // LIFO
#include <queue> // FIFO; priority_queue<T> with reverse-sorted insertion

// Namespaces
using namespace std;

// Driver
int main(int argc, char* argv[]) {
  vector<int> v = {1,2,3,5};
  stack<int,vector<int>> s(v); // stack<T,C<T>>; C = d, v or l
  s.pop(); // pop top
  s.push(6); // add top
  s.top() = 4; // access top

  stack<int,vector<int>> s2 = s;

  while (s2.size() > 0) {
    cout << s2.top() << " ";
    s2.pop();
  }
  cout << endl;

  deque<int> d = {5,6,2,3};
  queue<int> q(d); // queue<T,C<T>>; C = d, v or l
  q.pop(); // pop front
  q.push(7); // add back
  q.front() = 1; // access front
  q.back() = 4; // access back

  queue<int> q2 = q;

  while (q2.size() > 0) {
    cout << q2.front() << " ";
    q2.pop();
  }
  cout << endl;
}
