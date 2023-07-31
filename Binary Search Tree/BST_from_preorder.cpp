// https://www.codingninjas.com/studio/problems/preorder-traversal-to-bst_893111



#include <bits/stdc++.h> 
using namespace std;

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

BinaryTreeNode* solve(vector<int> &preorder, int &i , int mini, int maxi) {
    if (i >= preorder.size())
        return NULL;

    if (preorder[i] > mini && preorder[i] < maxi) {
        BinaryTreeNode* root = new BinaryTreeNode(preorder[i]);
        i++;

        root->left = solve(preorder, i, mini, root->data);
        root->right = solve(preorder, i, root->data, maxi);

        return root;
    }
    else {
        return NULL;
    }
}

BinaryTreeNode* preorderToBST(vector<int> &preorder) {
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;

    return solve(preorder, i, mini, maxi);

}