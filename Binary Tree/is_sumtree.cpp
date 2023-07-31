// https://practice.geeksforgeeks.org/problems/sum-tree/1

#include <utility>
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* left, * right;
}; 

// Should return true if tree is Sum Tree, else false
class Solution
{
    private:
    pair<bool, int> isSumTreeFast(Node* root) {
        // base case
        if (root == NULL) {
            pair<bool, int> p = make_pair(1,0);
            return p;
        }
        if (root->left == NULL && root->right == NULL) {
            pair<bool, int> p = make_pair(1,root->data);
            return p;
        }
        
        pair<bool, int> left = isSumTreeFast(root->left);
        pair<bool, int> right = isSumTreeFast(root->right);
        
        bool sumTree = (left.second + right.second) == root->data;
        
        pair<bool, int> ans;
        ans.first = left.first && right.first && sumTree;
        ans.second = left.second + right.second + root->data;
        
        return ans;
    }
    public:
    bool isSumTree(Node* root)
    {
         return isSumTreeFast(root).first;
    }
};