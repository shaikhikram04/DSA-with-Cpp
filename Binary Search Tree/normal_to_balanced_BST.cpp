// https://www.codingninjas.com/studio/problems/normal-bst-to-balanced-bst_920472?leftPanelTab=0


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


void inTraverse(TreeNode* root, vector<int> &inorder) {
    // base case
    if (root == NULL)
        return;

    inTraverse(root->left, inorder);
    inorder.push_back(root->data);
    inTraverse(root->right, inorder);
}

TreeNode* buildBalancedBST(vector<int> inorder, int s, int e) {
    if (s > e) {
        return NULL;
    }

    int mid = s + (e-s)/2;

    TreeNode* root = new TreeNode(inorder[mid]);

    root->left = buildBalancedBST(inorder, s, mid-1);
    root->right = buildBalancedBST(inorder, mid+1, e);

    return root;
}

TreeNode* balancedBst(TreeNode* root) {
    vector<int> inorder;
    inTraverse(root, inorder);

    return buildBalancedBST(inorder, 0, inorder.size() -1);
}
