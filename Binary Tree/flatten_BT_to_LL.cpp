// https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void flattenBT (Node* root) {
    Node* curr = root;
    while (curr != NULL) {
        if (curr->left) {
            Node* predecessor = curr->left;
            while (predecessor->right != NULL) {
                predecessor = predecessor->right;
            }

            predecessor->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}