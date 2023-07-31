// https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1

#include <iostream>
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

class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        if (node == NULL) {
            return 0;
        }
        // for left node
        int h1 = height(node->left);
        int h2 = height(node->right);

        int ans = max(h1, h2);
        return ans + 1;
    }
};