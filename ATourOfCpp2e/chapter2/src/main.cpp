/* ----------------------------------------------------------------------
   A Tour of C++ (2nd Edition) by Bjarne Stroustrup
   Chapter 2: User-Defined Types.
------------------------------------------------------------------------- */

#include <iostream>
#include "udts.h"

using namespace std;

int main()
{
  cout << "Hello World!" << endl;

  int s = 3;
  Vector v;
  vector_init(v, s);

  for (auto i=0; i!=s; ++i) {
    cout << "Enter v.elem["<< i <<"]:";
    cin>>v.elem[i]; // read into elements
  }

  for (auto i=0; i!=s; ++i)
    cout << v.elem[i] << '\n';

  printf("3 * v.sz = %i\n", sum_sz(v, v, &v));

  Vector2 v2(s);

  for (auto i=0; i!=s; ++i) {
    cout << "Enter v2["<< i <<"]:";
    cin>>v2[i]; // read into elements
  }

  for (auto i=0; i!=s; ++i)
    cout << v2[i] << '\n';

  // Linked List
  Node* head = NULL;
  Node* second = NULL;
  Node* third = NULL;

  // allocate 3 nodes in the heap
  head = new Node();
  second = new Node();
  third = new Node();

  head->data = 4; // assign data in first node
  head->next = second; // Link first node with the second node
  second->data = 5; // assign data to second node
  second->next = third; // Link second node with the third node
  third->data = 6; // assign data to third node
  third->next = NULL;

  Vector3 v3(s,ptr);

  (v3.type()==num)?printf("NUM\n"):printf("PTR\n");

  if (v3.type()==num) {
    v3[0].i = head->data; v3[1].i = second->data; v3[2].i = third->data;
  } else {
    v3[0].p = head; v3[1].p = second; v3[2].p = third;
  }

  for (auto i=0; i!=s; ++i)
    cout << v3[i].p << '\n';

  for (auto i=0; i!=s; ++i)
    cout << v3[i].i << '\n'; // this doesn't throw error, which is NOT good

/*
  Vector4 v4(s,num);

  (v4.type()==num)?printf("NUM\n"):printf("PTR\n");

  if (v4.type()==num) {
    v4[0] = head->data; v4[1] = second->data; v4[2] = third->data;
  } else {
    v4[0] = head; v4[1] = second; v4[2] = third;
  }

  for (auto i=0; i!=s; ++i)
    cout << v4[i] << '\n';
*/
  return 0;
}
