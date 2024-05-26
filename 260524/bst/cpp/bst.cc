#include "bst.hh"

void BST::createBST(int keys[], int size) {
    if (size <= 0) {
        throw std::invalid_argument("Input array cannot be empty");
    }
    try {
        root = new node(keys[0]);
        for (int i = 1; i < size; ++i) {
            Insert(keys[i]);
        }
    } catch (const std::bad_alloc& e) {
        std::cerr << "Memory allocation failed while creating BST: " << e.what() << std::endl;
        deleteAll(); // Clean up any nodes that may have been created
        throw;       // Rethrow the exception to indicate failure
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

bool BST::Search(int key, struct node*& res) const {
    struct node* troot = root;
    while (troot != nullptr) {
        if (troot->key == key) {
            res = troot;
            return true;
        }
        if (key < troot->key) {
            troot = troot->left;
        } else {
            troot = troot->right;
        }
    }
    res = nullptr;
    return false;
}

void BST::Insert(int key) {
    try {
        if (root == nullptr) {
            root = new node(key);
            return;
        }
        struct node* troot = root;
        struct node* parent = nullptr;
        while (troot != nullptr) {
            parent = troot;
            if (key < troot->key) {
                troot = troot->left;
            } else if (key > troot->key) {
                troot = troot->right;
            } else {
                throw std::invalid_argument("Duplicate key insertion is not allowed.");
            }
        }
        if (key < parent->key) {
            parent->left = new node(key);
        } else {
            parent->right = new node(key);
        }
    } catch (const std::bad_alloc& e) {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        throw;  // Rethrow the exception to be handled at a higher level if needed
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
        throw;  // Rethrow the exception to be handled at a higher level if needed
    }
}
