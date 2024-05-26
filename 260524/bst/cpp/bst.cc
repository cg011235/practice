#include "bst.hh"

#include <queue>
#include <stdexcept>

int BST::createBST(int keys[]) {
  int n = sizeof(keys)/sizeof(keys[0]);
  if (n <= 1) {
    throw std::invalid_argument("Input array can not be empty");
  }
  root = new node(keys[0]);
  struct node* t = root;
  struct node* p = nullptr;
  for (int i = 1; i < n; i++) {
    while(t != nullptr) {
      if (t->key < keys[i]) {
        p = t;
        t = t->left; 
      } else {
        p = t;
        t = t->right;
      }
    }
    if (p->key < keys[i]) {
      p->right = new node(keys[i]);
    } else {
      p->left = new node(keys[i]);
    } 
  }
  return 0;
}

int BST::deleteAll() {
  std::queue<struct node*> q;
  q.push(root);
  while (!q.empty()) {
    struct node* t = q.front();
    if (t->left != nullptr) {
      q.push(t->left);
    }
    if (t->right != nullptr) {
      q.push(t->right);
    }
    q.pop();
    delete t;
  }
  this->root = nullptr;
}