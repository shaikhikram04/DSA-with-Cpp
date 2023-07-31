// https://www.codingninjas.com/studio/problems/_893049?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0


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

    ~BinaryTreeNode() {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};


void solve(BinaryTreeNode* root, int key, BinaryTreeNode* &pred, BinaryTreeNode* &succ) {
    // base case
    if (root == NULL) {
        return;
    }

    if (root->data == key) {
        // for pred
        if (root->left) {
            pred = root->left;
            while (pred->right != NULL) 
                pred = pred->right;
        }

        // for succ
        if (root->right) {
            succ = root->right;
            while (succ->left) {
                succ = succ->left;
            }
        }

        return;
    }

    else if (root->data > key) {
        succ = root;
        solve(root->left, key, pred, succ);
    }
    else {
        pred = root;
        solve(root->right, key, pred, succ);
    }
}

pair<int,int> predecessorSuccessor(BinaryTreeNode* root, int key)
{
    BinaryTreeNode* pred = NULL;
    BinaryTreeNode* succ = NULL;
    solve(root, key, pred, succ);
    
    pair<int, int> ans;

    ans.first = (pred) ? pred->data : -1;
    ans.second = (succ) ? succ->data : -1;

    return ans;
}

