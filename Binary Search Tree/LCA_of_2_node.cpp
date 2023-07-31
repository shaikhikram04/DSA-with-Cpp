// https://www.codingninjas.com/studio/problems/lca-in-a-bst_981280?leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

class TreeNode {
    public :
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
        if(left)
            delete left;
        if(right)
            delete right;
    }
};


TreeNode* LCAinaBST(TreeNode* root, TreeNode* P, TreeNode* Q)
{
	if (root == NULL) {
        return NULL;
    }

    TreeNode* curr = root;
    int minNode = min(P->data, Q->data);
    int maxNode = max(P->data, Q->data);

    while (curr->data > maxNode || curr->data < minNode) {
        if (curr->data > maxNode)
            curr = curr->left;
        
        if (curr->data < minNode)
            curr = curr->right;
    }
    return curr;
}
