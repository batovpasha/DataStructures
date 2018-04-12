#include <iostream>
#include "trees.h"

using namespace std;
using namespace binary_tree;

int COUNT = 100;

int main() {
  Node *tree = nullptr;
  Node *negative_tree = nullptr;
  srand(time(nullptr));
  for (int i = 0; i < COUNT; i++) {
    float num = (float)(rand()) / RAND_MAX * (124.5325 + 1245.2144) - 145.2144;
    push(&tree, num);
  }
  make_negative_tree (&tree, &negative_tree);
  cout << "Main tree: ";
  print_tree(&tree);
  cout << endl;
  cout << "Negative tree: ";
  print_tree(&negative_tree);
  cout << endl;
}
