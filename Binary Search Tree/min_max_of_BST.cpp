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

void insertIntoBST(Node* &root, int data) {
    // base case
    if (root == NULL) {
        root = new Node(data);
        return;
    }

    if (data < root->data) {
        insertIntoBST(root->left, data);
    } else {
        insertIntoBST(root->right, data);
    }
}

void takeInput(Node* &root) {
    int data;
    cin >> data;

    while (data != -1) {
        insertIntoBST(root, data);
        cin >> data;
    }

    cout << "\nBST created" << endl;
}

int minVal(Node* root) {
    Node* curr = root;
    while (curr->left != NULL) {
        curr = curr->left;
    }
    return curr->data;
}

int maxVal(Node* root) {
    Node* curr = root;
    while (curr->right != NULL) {
        curr = curr->right;
    }
    return curr->data;
}

int main() {

    Node* root = NULL;

    // 8 3 10 14 1 6 7 4 13 -1

    cout << "Enter data for creating BST" << endl;
    takeInput(root);

    cout << "minimum value in BST is " << minVal(root) << endl;
    cout << "maximum value in BST is " << maxVal(root) << endl;

    return 0;
}