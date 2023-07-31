// https://www.codingninjas.com/studio/problems/h_920474?leftPanelTab=0

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


TreeNode* BSTFromInorder(vector<int> inorder, int s, int e) {
    if (s > e) {
        return NULL;
    }

    int mid = s + (e-s)/2;
    TreeNode* root = new TreeNode(inorder[mid]);

    root->left = BSTFromInorder(inorder, s, mid-1);
    root->right = BSTFromInorder(inorder, mid+1, e);

    return root;
}

void inTraverse(TreeNode* root, vector<int> &inorder) {
    // base case
    if (root == NULL)
        return;

    inTraverse(root->left, inorder);
    inorder.push_back(root->data);
    inTraverse(root->right, inorder);
}

TreeNode *mergeBST(TreeNode *root1, TreeNode *root2){
    vector<int> first;
    inTraverse(root1, first);
    int n = first.size();

    vector<int> second;
    inTraverse(root2, second);
    int m = second.size();

    vector<int> inorder;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (first[i] < second[j]) {
            inorder.push_back(first[i++]);
        } else {
            inorder.push_back(second[j++]);
        }
    }
    while (i < n) {
        inorder.push_back(first[i++]);
    }
    while (j < m) {
        inorder.push_back(second[j++]);
    }

    return BSTFromInorder(inorder, 0, inorder.size()-1);
}
