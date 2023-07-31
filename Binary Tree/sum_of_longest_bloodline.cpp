// https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

#include <iostream>
using namespace std;

//User function Template for C++


struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
    void solve(Node* root, int len, int sum, int &maxLen, int &maxSum) {
        if (root == NULL) {
            
            if (len > maxLen) {
                maxLen = len;
                maxSum = sum;
            }
            else if (len == maxLen) {
                maxSum = max(sum, maxSum);
            }
            
            return ;
        }
            
        sum += root->data;
            
        solve(root->left, len+1, sum, maxLen, maxSum);
        solve(root->right, len+1, sum, maxLen, maxSum);
    }
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int len = 1;
        int maxLen = 0;
        
        int sum = 0;
        int maxSum = 0;
        
        solve (root, len, sum, maxLen, maxSum);
        
        return maxSum;
    }
};