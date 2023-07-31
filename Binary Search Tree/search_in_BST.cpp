// https://www.codingninjas.com/codestudio/problems/search-in-bst_1402878?leftPanelTab=0


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
    if (root == NULL) {
        return false;
    }
    if (x == root->data) {
        return true;
    }

    if (x < root->data) {
        return searchInBST(root->left, x);
    }
    else {
        return searchInBST(root->right, x);
    }
}