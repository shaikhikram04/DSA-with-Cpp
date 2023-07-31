// https://practice.geeksforgeeks.org/problems/k-sum-paths/1

#include <bits/stdc++.h>
using namespace std;


struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution{
  public:
    void solve(Node* root, int k, int &count, vector<int> path) {
        if (root == NULL)
            return ;
            
        path.push_back(root->data);
        
        // check for k sum
        int size = path.size();
        int sum = 0;
        for (int i = size-1; i >= 0; i--) {
            sum += path[i];
            if (sum == k) {
                count++;
            }
        }
        
        // left
        solve(root->left, k, count, path);
        // right
        solve(root->right, k, count, path);
        
        
        path.pop_back();
    }
    int sumK(Node *root,int k)
    {
        vector<int> path;
        int count = 0;
        solve(root, k, count, path);
        return count;
    }
};