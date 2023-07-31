// https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1


#include <iostream> 
#include <utility>
using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution{
    pair<int, int> solve(Node* root) {
        // base case
        if (root == NULL) {
            return {0, 0};
        }
        
        pair<int, int> leftAns = solve(root->left);
        pair<int, int> rightAns = solve(root->right);
        
        pair<int, int> ans;
        
        // included part
        ans.first = root->data + leftAns.second + rightAns.second;
        
        // exclude part
        ans.second = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);
        
        return ans;
    }
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};