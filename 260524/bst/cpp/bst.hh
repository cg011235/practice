#pragma once

struct node {
  int key;
  struct node* left;
  struct node* right;
  node(int key): key(key), left(nullptr), right(nullptr) {}
};

class BST {
  public:
    BST(int keys[]) {
      createBST(keys);
    }
    ~BST() {
      deleteAll();
    }
  private:
    int createBST(int keys[]);
    int deleteAll();
    struct node* root;
};