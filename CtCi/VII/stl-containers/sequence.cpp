/* ----------------------------------------------------------------------
   Cracking the Coding interview (6th Edition) by G. L. McDowell
   VII: STL Containers - sequence.
   Coding Ref: https://www.geeksforgeeks.org/containers-cpp-stl/
------------------------------------------------------------------------- */

// Includes
#include <iostream>
#include <string>

// for C-style array container, no include needed
#include <array> // a C++-style array container, for homogeneous type elements
#include <tuple> // NOT a container, for heterogenous type elements

#include <vector> // expandable contiguous array
#include <deque> // double ended queue; inexpensive front insert/delete

// slow traversal than vector/deque but insert/delete upon locating is fast
#include <forward_list> // when only forward traversal is required; saves space
#include <list> // non-contiguous linked list; can be iterated both directions

// Namespaces
using namespace std;

// Driver
int main(int argc, char* argv[]) {
  int carr[5] = {1,2,3,4,5};
  cout << carr[1] << endl;
  cout << sizeof(carr)/sizeof(carr[0]) << endl;

  array<int,5> cpparr = {1,2,3,4,5};
  cout << cpparr.at(1) << endl;
  cout << cpparr.size() << endl;

  pair<char,int> p;
  p = make_pair('1',2);

  tuple<char,int,float,double,string> cpptup;
  cpptup = make_tuple('1',2,3.0,4.0,"5");
  cout << get<1>(cpptup) << endl;
  cout << tuple_size<decltype(cpptup)>::value << endl;

  vector<int> v = {1,2,3,4};
  v.push_back(6); // append
  // v.insert(4,5); // ERROR
  v.insert(v.begin()+4,5); // insert 5 before the 4th position (before the 6)
  v.pop_back(); // remove end

  for (auto elem : v) {
    cout << elem << " ";
  }
  cout << endl;

  deque<int> d = {7,2,3,4,6};
  d.pop_back();
  d.pop_front(); // remove begin also
  d.push_back(5);
  d.push_front(1); // prepend also

  for (auto it = d.begin(); it != d.end(); ++it) {
    cout << *it << " ";
  }
  cout << endl;

  forward_list<int> fl;
  fl.assign({7,6,5});
  fl.pop_front();
  fl.push_front(1);
  fl.remove(6);
  forward_list<int> spl = {2,3,4};
  fl.splice_after(fl.begin(),spl);

  for (int& elem : fl) {
    cout << elem << " ";
  }
  cout << endl;

  list<int> l = {3,2,4,1,5};
  l.reverse();
  l.sort();

  for (auto it = l.begin(); it != l.end(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
}
