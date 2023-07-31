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


pair<int,int> predecessorSuccessor(BinaryTreeNode* root, int key)
{
    int pre = -1;
    int suc = -1;
    
    // find key
    BinaryTreeNode* temp = root;
    while (temp->data != key) {
        if(temp->data > key) {
            suc = temp->data;
            temp = temp->left;
        }
        else {
            pre = temp->data;
            temp = temp->right;
        }
    }
    
    // find pre & succ
    BinaryTreeNode* leftTree = temp->left;
    while (leftTree != NULL) {
        pre = leftTree->data;
        leftTree = leftTree->right;
    }
    
    BinaryTreeNode* rightTree = temp->right;
    while (rightTree != NULL) {
        suc = rightTree->data;
        rightTree = rightTree->left;
    }
    
    return {pre, suc};
}
