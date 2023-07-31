// https://practice.geeksforgeeks.org/problems/bst-to-max-heap/1


#include <bits/stdc++.h> 
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

class Solution{
    
    void inTraversal(Node* root, vector<int> &arr) {
        if (root == NULL)
            return ;
            
        inTraversal(root->left, arr);
        arr.push_back(root->data);
        inTraversal(root->right, arr);
    }
    
    void postTraversal(Node* root, vector<int> &inorder, int &i) {
        if (root == NULL)
            return;
            
        postTraversal(root->left, inorder, i);
        postTraversal(root->right, inorder, i);
        root->data = inorder[i++];
    }
    
  public:
    void convertToMaxHeapUtil(Node* root)
    {
        vector<int> inorder;
        inTraversal(root, inorder);
        
        int i = 0;
        postTraversal(root, inorder, i);
        
    }    
};