// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

#include <bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
private:
    void leftBoundary(Node* root, vector<int> &ans) { 
        // base case
        if (root == NULL || (root->right == NULL && root->left == NULL))
            return;
        
        
        ans.push_back(root->data);
        
        if (root->left)
            leftBoundary(root->left, ans);
        
        else 
            leftBoundary(root->right, ans);
        
    }

    void leafNode(Node* root, vector<int> &ans) {
        if (root == NULL)
            return;
        
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(root->data);
            return;
        }
        
        leafNode(root->left, ans);
        leafNode(root->right, ans);
    }
    
    void rightBoundary(Node* root, vector<int> &ans) {
        if (root == NULL || (root->right == NULL && root->left == NULL)) 
            return;
        
        
        if (root->right)
            rightBoundary(root->right, ans);
        
        else 
            rightBoundary(root->left, ans);
        
        ans.push_back(root->data);
    }
public:
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
            
        ans.push_back(root->data);
        
        // left boundary node
        leftBoundary(root->left, ans);
        
        // left part 
        if (root->right != NULL || root->left != NULL)
        leafNode(root, ans);
        
        // right part
        rightBoundary(root->right, ans);       
            
        return ans;
    }
};