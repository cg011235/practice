#pragma once

#include <queue>

struct node {
    int key;
    struct node* left;
    struct node* right;
    node(int key) : key(key), left(nullptr), right(nullptr) {}
};

class BST {
public:
    BST(int keys[], int size) : root(nullptr) {
        createBST(keys, size);
    }
    ~BST() {
        deleteAll();
    }
private:
    void createBST(int keys[], int size);
    void deleteAll();
    struct node* root;
};
