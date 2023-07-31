// https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    int countNode(struct Node* tree) {
        if (tree == NULL)
            return 0;
            
        int cnt = 1 + countNode(tree->left) + countNode(tree->right);
        return cnt;
    }
    
    bool isCBT(struct Node* tree, int index, int totalNode) {
        // base case
        if (tree == NULL)
            return true;
            
        if (index >= totalNode)
            return false;
            
        bool left = isCBT(tree->left, 2*index + 1, totalNode);
        bool right = isCBT(tree->right, 2*index + 2, totalNode);
        
        return left && right;
    }
    
    bool isMaxOrder(struct Node* tree) {
        // base case
        // left node
        if (tree->left == NULL && tree->right == NULL) 
            return true;
            
        // left node only
        else if (tree->right == NULL)
            return (tree->left->data < tree->data);
            
        // both node
        bool left = isMaxOrder(tree->left);
        bool right = isMaxOrder(tree->right);
        
        
        return (left && right && (tree->left->data < tree->data && tree->right->data < tree->data));
    }
    
  public:
    bool isHeap(struct Node* tree) {
        
        int index = 0;
        int totalNode = countNode(tree);
        return (isCBT(tree, index, totalNode) && isMaxOrder(tree));
    }
};
