#include <iostream>
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

int minVal(Node* root) {
    Node* curr = root;
    while (curr->left != NULL) {
        curr = curr->left;
    }
    return curr->data;
}

Node* deleteNode (Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    // key found
    if (key == root->data) {
        // 0 child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // 1 child

        // left child
        if (root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // right child
        else if (root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left && root->right) {
            int mini = minVal(root->right);
            root->data = mini;
            root->right = deleteNode(root->right, mini);
            return root;
        }
    }

    // key is smaller
    else if (key < root->data) {
        root->left = deleteNode(root->left, key);
        return root;
    }

    // key is bigger
    else {
        root->right = deleteNode(root->right, key);
        return root;
    }
}