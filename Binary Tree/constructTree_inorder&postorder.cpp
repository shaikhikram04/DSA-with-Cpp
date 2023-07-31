// https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1

#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void createMapping(int in[], map<int, int> &nodeToIndex, int n) {
    for (int i = 0; i < n; i++) {
        nodeToIndex[in[i]] = i;
    }
}

Node* solve(int in[], int post[], map<int, int> &nodeToIndex, int &index, int inStart, int inEnd, int n) {
    // base case
    if (index < 0 || inStart > inEnd) {
        return NULL;
    }
    
    int element = post[index--];
    Node* node = new Node(element);
    
    int position = nodeToIndex[element];
    
    node->right = solve(in, post, nodeToIndex, index, position+1, inEnd, n);
    node->left = solve(in, post, nodeToIndex, index, inStart, position-1, n);
    
    return node;
} 

Node *buildTree(int in[], int post[], int n) {
    map<int, int> nodeToIndex;
    createMapping(in, nodeToIndex, n);
    
    int postorderIndex = n-1;
    Node* root = solve(in, post, nodeToIndex, postorderIndex, 0, n-1, n);
    
    return root;
}