// https://www.codingninjas.com/studio/problems/two-sum-in-a-bst_1062631?leftPanelTab=1

#include <bits/stdc++.h> 
using namespace std;

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

void traverse(BinaryTreeNode* root, vector<int> &inorder)  {
    if (root == NULL)
        return ;

    traverse(root->left, inorder);
    inorder.push_back(root->data);
    traverse(root->right, inorder);
}

bool twoSumInBST(BinaryTreeNode* root, int target) {
    vector<int> inorder;    
    traverse(root, inorder);

    int i = 0, j = inorder.size()-1;
    while (i < j) {
        int sum = inorder[i] + inorder[j];
        if (sum == target)
            return true;
        else if (sum < target)
            i++;
        else    
            j--;
    }

    return false;
}