/* ----------------------------------------------------------------------
   Cracking the Coding interview (6th Edition) by G. L. McDowell
   VII: Trees and Graphs.
   Coding Ref: http://www-h.eng.cam.ac.uk/help/tpl/talks/C++graphs.html
------------------------------------------------------------------------- */

/*
If a binary tree remains balanced, then it could fit 10,000 words within
15 layers, so a word-search would require only 15 comparisons at most.
Insertions (new nodes) are cheap too. Contrast this with the worst case array
scenario, where 10,000 comparisons may be needed before a search is complete!
However, if the words are supplied in alphabetical order, this tree-based
method suffers - each new word will add a right-node, deepening the tree each
time, making searching as slow as with arrays. Various techniques exist to
combat this. The benefits of these techniques are so enormous that simple
binary trees aren't used in big programs.
*/

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
