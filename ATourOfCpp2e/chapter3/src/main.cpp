/* ----------------------------------------------------------------------
   A Tour of C++ (2nd Edition) by Bjarne Stroustrup
   Chapter 3: Modularity.
------------------------------------------------------------------------- */

#include <iostream>
#include <typeinfo>
#include <iterator>
#include <map>
#include "udts.h"
#include "udts2.h"

//using namespace std; // This is OK only as long as you don't want to define a type that with the same name as in std

int main()
{
  std::cout << "Hello World!" << std::endl;

  int s = 3;
  Vector v(s);

  for (auto i=0; i!=s; ++i) {
    std::cout << "Enter v["<< i <<"]:";
    std::cin>>v[i]; // read into elements
  }

  for (auto i=0; i!=s; ++i)
    std::cout << v[i] << '\n';

  try { // exceptions here are handled by the handler defined below
    v[v.size()] = 7; // try to access beyond the end of v
  }
  catch (std::out_of_range& err) { // oops: out_of_range error
    // ... handle range error by just telling what it is and carry on ...
    std::cerr << err.what() << " had an error and operation is skipped."<< '\n';
  }

  pranjal::main();

  // Structured binding (WARNING: G++7 OR HIGHER is required for this C++17 feature)
  auto e = read_entry(std::cin);
  std::cout << "{ " << e.name << " , " << e.value << " }\n";
  std::cout << "{ " << typeid(e.name).name() << " , " << typeid(e.value).name() << " }\n";

  auto [a,b] = read_entry(std::cin);
  std::cout << "{ " << a << " , " << b << " }\n";

  // Mapping
  std::map<std::string,int> m;
  m.insert(std::pair<std::string, int>("a", 2));
  m.insert(std::pair<std::string, int>("b", 4));
  m.insert(std::pair<std::string, int>("c", 8));
  m.insert(std::pair<std::string, int>("d", 16));
  m.insert(std::pair<std::string, int>("e", 32));

  for (const auto [key,value] : m)
    std::cout << "{" << key << "," << value << "}\n";

  incr(m);
  for (const auto [key,value] : m)
    std::cout << "{" << key << "," << value << "}\n";


  return 0;
}
