#include <bits/stdc++.h>
using namespace std;


struct Node
{
	int data;
	struct Node *left, *right;
};


Node* solve(Node* root, int &k, int node) {
    if (root == NULL)
        return NULL;
        
    if (root->data == node){
        return root;
    }    
    
    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);
    
    if (leftAns || rightAns) {
        k--;
        if (k <= 0) {
            k = INT_MAX;
            return root;
        }
        
        if (leftAns)
            return leftAns;
        else
            return rightAns;
    }
    else {
        return NULL;
    }
    
}

int kthAncestor(Node *root, int k, int node)
{
    Node* ans = solve(root, k, node);
    if (ans == NULL || ans->data == node)
        return -1;
        
    else
        return ans->data;
}