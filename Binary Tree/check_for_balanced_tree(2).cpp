#include <utility>
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
    private:
    pair<bool, int> checkBalanced(Node* root) {
        if (root == NULL) {
            pair<bool, int> ans = make_pair(1,0);
            return ans;
        }
        
        pair<bool, int> left = checkBalanced(root->left);
        pair<bool, int> right = checkBalanced(root->right);
        
        pair<bool, int> ans;
        ans.first = left.first && right.first && abs(left.second - right.second) <= 1;
        ans.second = max(left.second, right.second) + 1;
        
        return ans;
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return checkBalanced(root).first;
    }
};