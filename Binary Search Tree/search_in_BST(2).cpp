#include <bits/stdc++.h> 


class BinaryTreeNode {
public : 
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};


bool searchInBST(BinaryTreeNode *root, int x) {
    BinaryTreeNode* curr = root;
    while (curr != NULL) {
        if (x == curr->data)
            return true;
            
        if (x < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return false;
}