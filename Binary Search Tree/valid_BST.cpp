// https://www.codingninjas.com/studio/problems/validate-bst_799483?leftPanelTab=0


#include <bits/stdc++.h> 
 

class BinaryTreeNode 
{
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

bool isBST(BinaryTreeNode *root, int mini, int maxi) {
    if (root == NULL) {
        return true;
    }
    
    if ((root->data >= mini) && (root->data <= maxi)) {
        bool leftAns = isBST(root->left, mini, root->data);
        bool rightAns = isBST(root->right, root->data, maxi);
        return leftAns && rightAns;
    }
    else {
        return false;
    }
}

bool validateBST(BinaryTreeNode *root) {
    return isBST(root, INT_MIN, INT_MAX);
}