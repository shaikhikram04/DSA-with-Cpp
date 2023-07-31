// https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1

#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// Should return  right view of tree
class Solution
{
    void solve(Node* root, int lvl, vector<int> &ans) {
        // base case
        if (root == NULL)
            return;
            
        if (lvl == ans.size())
            ans.push_back(root->data);
            
        solve(root->right, lvl+1, ans);
        solve(root->left, lvl+1, ans);
    }
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       vector<int> ans;
       solve(root, 0, ans);
       return ans;
    }
};
