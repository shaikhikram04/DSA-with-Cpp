
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node (int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(Node* root) {
    int data;
    cout << "Enter data : ";
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    root = new Node(data);

    cout << "For inserting left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "For inserting right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

Node* findPredecessor(Node* root) {
    Node* predecessor = root->left;
    while (predecessor->right != NULL && predecessor->right != root) {
        predecessor = predecessor->right;
    }
    return predecessor;
}

void inMorrisTraversal(Node* root) {
    Node* curr = root;
    while (curr != NULL) {
        if (curr->left == NULL) {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else {
            Node* predecessor = findPredecessor(curr);
            if (predecessor->right == NULL) {
                predecessor->right = curr;
                curr = curr->left;
            }
            else {
                predecessor->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}

void preMorrisTraversal(Node* root) {
    Node* curr = root;
    while (curr != NULL) {
        if (curr->left == NULL) {
            cout << curr->data << " ";
            curr = curr->right;
        } else {
            Node* predecessor = findPredecessor(curr);
            if (predecessor->right == NULL) {
                predecessor->right = curr;
                cout << curr->data << " ";
                curr = curr->left;
            } else {
                predecessor->right = NULL;
                curr = curr->right;
            }
        }
    }
}


int main() {
    Node* root = NULL;
    root = buildTree(root);
    // 1 2 4 7 -1 -1 8 -1 -1 5 -1 9 -1 -1 3 -1 6 10 -1 -1 -1

    cout << "\n\n Inorder Morris Traversal" << endl;
    inMorrisTraversal(root);

    cout << "\n\n Preorder Morris Traversal" << endl;
    preMorrisTraversal(root);

    return 0;
}

