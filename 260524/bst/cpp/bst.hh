#pragma once

#include <queue>
#include <stdexcept>
#include <iostream>

struct node {
    int key;
    struct node* left;
    struct node* right;
    node(int key) : key(key), left(nullptr), right(nullptr) {}
};

class BST {
public:
    BST() : root(nullptr) {}
    BST(int keys[], int size) : root(nullptr) {
        createBST(keys, size);
    }
    ~BST() {
        deleteAll();
    }
    bool Search(int key, struct node*& res) const;
    void Insert(int key);
private:
    void createBST(int keys[], int size);
    void deleteAll();
    struct node* root;
};
