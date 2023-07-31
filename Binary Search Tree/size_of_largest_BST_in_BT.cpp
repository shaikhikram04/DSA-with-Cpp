// https://www.codingninjas.com/studio/problems/largest-bst-subtree_893103?leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

class TreeNode{

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
        if (left){
        delete left;
        }

        if (right){
        delete right;
        }
    }   
};

class info {
public : 
    int mini;
    int maxi;
    bool isBST;
    int size;
};

info solve(TreeNode* root, int &maxSize) {
    // base case
    if (root == NULL) {
        return {INT_MAX, INT_MIN, true, 0};
    }
    
    info left = solve(root->left, maxSize);
    info right = solve(root->right, maxSize);

    info currNode;

    currNode.mini = min(left.mini, root->data);
    currNode.maxi = max(right.maxi, root->data);
    currNode.size = left.size + right.size + 1;

    if (left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)){
        currNode.isBST = true;
        maxSize = max(currNode.size, maxSize);
    }
    else {
        currNode.isBST = false;
    }
    return currNode;
}

int largestBST(TreeNode* root) 
{
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}
