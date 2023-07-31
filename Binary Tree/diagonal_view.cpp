// https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* left, * right;
};


void solve(Node* root, int hd, map<int, vector<int> > &diagonalNodes) {
    if (root == NULL)
        return;
        
    diagonalNodes[hd].push_back(root->data);
    
    solve(root->left, hd + 1, diagonalNodes);
    solve(root->right, hd, diagonalNodes);
}

vector<int> diagonal(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
        
    map<int, vector<int> > diagonalNodes;
    
    
    solve(root, 0, diagonalNodes);
    
    for (auto i : diagonalNodes)
        for (auto j : i.second)
            ans.push_back(j);
            
            
    return ans;
}