// https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1


#include <bits/stdc++.h>
using namespace std;



struct Node
{
	int data;
	struct Node *left, *right;
};


void solve(Node* root, int k, int node, vector<int> path,int &ans) {
    if (root == NULL)
        return ;
        
    path.push_back(root->data);
    
    if (root->data == node){
        int size = path.size();
        if (size <= k)
            return;
            
        ans = path[size - k - 1];
        return;
    }
    
    solve(root->left, k, node, path, ans);
    solve(root->right, k, node, path, ans);
    
    
}
int kthAncestor(Node *root, int k, int node)
{
    int ans = -1;
    vector<int> path;
    solve(root, k, node, path, ans);
    return ans;
}
 