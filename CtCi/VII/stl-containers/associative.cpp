/* ----------------------------------------------------------------------
   Cracking the Coding interview (6th Edition) by G. L. McDowell
   VII: STL Containers - associative.
   Coding Ref: https://www.geeksforgeeks.org/containers-cpp-stl/
------------------------------------------------------------------------- */

// Includes
#include <iostream>
#include <string>

#include <set> // unique sorted keys with immutable unindexed values; bnry-srch
#include <map> // each key has a unique mapped value

// following 'unordered' associative containers implement unsorted (hashed)
// data structures which quickly search (O(1) amortized, O(n) worst-case)
// unordered_set<T>, unordered_map<T1,T2>, unordered_multiset<T> and
// unordered_multimap<T1,T2>

// Namespaces
using namespace std;

// Driver
int main(int argc, char* argv[]) {
  set<int> s1 = {9,2,4,1,5,3,6,7};
  s1.insert(3); // this won't be added, for allowing repetetion use multiset

  for (auto it = s1.begin(); it != s1.end(); ++it) {
    cout << *it << " ";
  }
  cout << endl;

  set<int> s2(s1.begin(),s1.end());
  s2.erase(s2.find(7),s2.end());
  s2.erase(6);

  for (auto elem : s2) {
    cout << elem << " ";
  }
  cout << endl;

  map<string, int> m = {{"a",1}};
  m.insert(pair<string,int>("b",2)); // this is cumbersome for map, but is only
                                     // way to add non-unique pairs in multimap
  m["c"] = 4;
  m["c"] = 3; // this replaces m["c"]; not a new entry

  cout << m.at("b") << endl; // this will not work in multimap

  for (auto elem : m) {
    cout << elem.first << " ";
  }
  cout << endl;
  for (auto it = m.begin(); it != m.end(); ++it) {
    cout << it->second << " ";
  }
  cout << endl;
}
