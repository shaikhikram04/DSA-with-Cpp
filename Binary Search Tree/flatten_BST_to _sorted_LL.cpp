// https://www.codingninjas.com/studio/problems/flatten-bst-to-a-sorted-list_1169459?leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

class TreeNode {
    public :
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
        if(left)
            delete left;
        if(right)
            delete right;
    }
};


void traverse(TreeNode* root, vector<int> &inorder){
    if (root == NULL)
        return;

    traverse(root->left, inorder);
    inorder.push_back(root->data);
    traverse(root->right, inorder);
}

TreeNode* flatten(TreeNode* root)
{
    vector<int> inorder;
    traverse(root, inorder);
    int n = inorder.size();

    TreeNode* newRoot = new TreeNode(inorder[0]);
    TreeNode* curr = newRoot;

    for (int i = 1; i < n; i++) {
        TreeNode* temp = new TreeNode(inorder[i]);
        curr->right = temp;
        curr = temp;
    }
    
    return newRoot;
}
