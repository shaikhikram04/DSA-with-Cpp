// https://practice.geeksforgeeks.org/problems/construct-tree-1/1

#include <bits/stdc++.h>
using  namespace std;


class Node {
public: 
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution{
    
    int findPosition(int in[], int s, int e, int element) {
        for (int i = s; i <= e; i++) {
            if (in[i] == element)
                return i;
        }
        return -1;
    }
    
    Node* solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n) {
        // base case
        if (index >= n || inorderStart > inorderEnd)
            return NULL;
            
        int element = pre[index++];
        Node* root = new Node(element);
        
        int position = findPosition(in, inorderStart, inorderEnd, element);
        
        root->left = solve(in, pre, index, inorderStart, position-1, n);
        root->right = solve(in, pre, index, position+1, inorderEnd, n);
        
        return root;
    }
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderIndex = 0;
        Node* ans = solve(in, pre, preOrderIndex, 0, n-1, n);
        return ans;
    }
};