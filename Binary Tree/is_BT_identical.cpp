// https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1

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


   
class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        if (r1 == NULL && r2 == NULL) {
            return true;
        }
        if ((r1 == NULL && r2 != NULL) || (r1 != NULL && r2 == NULL) || (r1->data != r2->data)) {
            return false;
        }
        
        bool left = isIdentical(r1->left, r2->left);
        bool right = isIdentical(r1->right, r2->right);
        
        return (left && right);
    }
};