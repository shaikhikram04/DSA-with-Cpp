#include <bits/stdc++.h> \
 
   

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
};


int kthSmallest(BinaryTreeNode* root, int k) {
    int cnt = 0;
    BinaryTreeNode* curr = root;
    while (curr != NULL) {
        if (curr->left == NULL) {
            cnt++;
            if (cnt == k)
                return curr->data;
            curr = curr->right;
        }
        else {
            BinaryTreeNode* pred = curr->left;
            while (pred->right != NULL && pred->right != curr) {
                pred = pred->right;
            }
            if (pred->right == NULL) {
                pred->right = curr;
                curr = curr->left;
            }
            else {
                pred->right = NULL;
                cnt++;
                if (cnt == k)
                    return curr->data;
                    
                curr = curr->right;
            }
        }
    }
    
    return -1;
}