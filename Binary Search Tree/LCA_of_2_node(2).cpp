#include <bits/stdc++.h> 

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

    if (root->data < P->data && root->data < Q->data)
        return LCAinaBST(root->right, P, Q);

    if (root->data > P->data && root->data > Q->data)
        return LCAinaBST(root->left, P, Q);   

    return root;
}
