#include "bst.hh"

#include <queue>
#include <stdexcept>

void BST::createBST(int keys[], int size) {
    if (size <= 0) {
        throw std::invalid_argument("Input array cannot be empty");
    }
    root = new node(keys[0]);
    for (int i = 1; i < size; ++i) {
        node* t = root;
        node* p = nullptr;
        while (t != nullptr) {
            p = t;
            if (keys[i] < t->key) {
                t = t->left;
            } else {
                t = t->right;
            }
        }
        if (keys[i] < p->key) {
            p->left = new node(keys[i]);
        } else {
            p->right = new node(keys[i]);
        }
    }
}

void BST::deleteAll() {
    if (root == nullptr) return;
    std::queue<struct node*> q;
    q.push(root);
    while (!q.empty()) {
        struct node* t = q.front();
        q.pop();
        if (t->left != nullptr) {
            q.push(t->left);
        }
        if (t->right != nullptr) {
            q.push(t->right);
        }
        delete t;
    }
    root = nullptr;
}
