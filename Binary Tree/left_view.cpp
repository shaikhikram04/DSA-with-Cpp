// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

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


//Function to return a list containing elements of left view of the binary tree.

void solve(Node* root, int lvl, vector<int> &ans) {
    // base case
    if (root == NULL)
        return ;
        
    if (ans.size() == lvl)
        ans.push_back(root->data);
        
    solve(root->left, lvl+1, ans);
    solve(root->right, lvl+1, ans);
}

vector<int> leftView(Node *root)
{
    vector<int> ans;
    int lvl = 0;
    
    solve(root, lvl, ans);
    
    return ans;
    
}