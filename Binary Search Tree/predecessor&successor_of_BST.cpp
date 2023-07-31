#include <iostream>
#include <utility>
using namespace std;

class Node {
public: 
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* minNode(Node* root) {
    Node* curr = root;
    while (curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

Node* maxNode(Node* root) {
    Node* curr = root;
    while (curr->right != NULL) {
        curr = curr->right;
    }
    return curr;
}

void findPredecessor(Node* root, Node* &predecessor, int key) {
    // base case
    if (root == NULL) {
        predecessor = NULL;
        return;
    }

    // found key
    if (root->data == key) {
        if (root->left) {
            predecessor = maxNode(root->left);
            return;
        }
    }

    // key is smaller
    else if (key < root->data) {
        findPredecessor(root->left, predecessor, key);
    }

    // key is bigger
    else {
        predecessor = root;
        findPredecessor(root->right, predecessor, key);
    }
}

void findSuccessor(Node* root, Node* &successor, int key) {
    // base case
    if (root == NULL) {
        successor = NULL;
        return;
    }

    // found key
    if (key == root->data) {
        if (root->right) {
            successor = minNode(root->right);
            return;
        }
    }

    // key is smaller
    else if (key < root->data) {
        successor = root;
        findSuccessor(root->left, successor, key);
    }

    // key is bigger
    else {
        findSuccessor(root->right, successor, key); 
    }
}