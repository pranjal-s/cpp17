/* ----------------------------------------------------------------------
   Cracking the Coding interview (6th Edition) by G. L. McDowell
   VII: Linked Lists.
------------------------------------------------------------------------- */

// Includes
#include<iostream>

// Namespaces
using namespace std;

// Structures
struct Node {
  double data;
  Node* next;
};

// Driver
int main(int argc, char* argv[]) {
  Node* head = new Node();
  Node* second = new Node();
  Node* third = new Node();

  head->data=1;
  head->next=second;
  second->data=2;
  second->next=third;
  third->data=3;
  third->next=nullptr;
}
