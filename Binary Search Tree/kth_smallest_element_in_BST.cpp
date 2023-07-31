// https://www.codingninjas.com/studio/problems/find-k-th-smallest-element-in-bst_1069333?leftPanelTab=0

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

void solve (BinaryTreeNode* root, int k, int &cnt, int &ans) {
    if (root == NULL)
        return ;

    solve(root->left, k, cnt, ans);
    cnt++;
    if(cnt == k)
        ans = root->data;

    solve(root->right, k, cnt, ans);
}

int kthSmallest(BinaryTreeNode* root, int k) {
    int cnt = 0, ans = -1;

    solve(root, k, cnt, ans);
    return ans;
}