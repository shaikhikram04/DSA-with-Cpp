// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1


#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        if (root == NULL) 
            return ans;
            
        map<int, int> bottomNodes;
        queue<pair<Node*, int> > q;
        
        q.push(make_pair(root, 0));
        
        while (!q.empty()) {
            pair<Node*, int> temp = q.front();
            Node* frontNode = temp.first;
            int hd = temp.second;
            q.pop();
            
            bottomNodes[hd] = frontNode->data;
            
            if (frontNode->left) 
                q.push(make_pair(frontNode->left, hd-1));
                
            if (frontNode->right)
                q.push(make_pair(frontNode->right, hd+1));
                
        }
        
        for (auto i : bottomNodes)
            ans.push_back(i.second);
            
        return ans;
    }
};