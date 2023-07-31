// https://www.codingninjas.com/studio/problems/convert-bst-to-min-heap_920498?leftPanelTab=0


#include <bits/stdc++.h> 
using namespace std;

class BinaryTreeNode {
    
public :
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int data) {
    this -> left = NULL;
    this -> right = NULL;
    this -> data = data;
    }
};


void solve(BinaryTreeNode* root) {
	if (root->left == NULL && root->right == NULL) 
		return;

	if (root->data < root->left->data && root->data < root->right->data) {
		return;
	}

	solve(root->left);
		
	if (root->right == NULL) {
		swap(root->data, root->left->data);
		return;
	}
	
	if (root->left < root->right) {
		swap(root->data, root->left->data);
		solve(root->left);
	}
	else {
		swap(root->data, root->right->data);
		solve(root->right);
	}
	
	solve(root->right);	
	
}

BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	solve(root);
	return root;
}