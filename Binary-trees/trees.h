#include <iostream>

using namespace std;

namespace binary_tree {
  struct Node {
    float data;
    Node *left;
    Node *right;
  };

  void print_tree(Node **tree) {
    if ((*tree) != nullptr) {
      print_tree(&(*tree)->left);
      cout << (*tree)->data << " ";
      print_tree(&(*tree)->right);
    }
  }

  void push(Node **tree, float number) {
    if ((*tree) == nullptr) {
      (*tree) = new Node;
      (*tree)->data = number;
      (*tree)->left = nullptr;
      (*tree)->right = nullptr;
      return;
    }
    if (number > (*tree)->data) push(&(*tree)->right, number);
    else push(&(*tree)->left, number);
  }

  Node *make_negative_tree(Node **tree, Node **negative_tree) {
    if ((*tree) != nullptr) {
      make_negative_tree(&(*tree)->left, &(*negative_tree));
      if((*tree)->data < 0) push(&(*negative_tree), (*tree)->data);
      make_negative_tree(&(*tree)->right, &(*negative_tree));
    }
  }
};
