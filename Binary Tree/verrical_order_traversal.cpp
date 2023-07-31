// https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1


#include <bits/stdc++.h>
using namespace std;

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


class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        map<int, vector<int> > nodes;
        queue<pair<Node* , int> > q;
        vector<int> ans; 
        
        if (root == NULL)
            return ans;
            
        q.push(make_pair(root, 0));
        
        while (!q.empty()) {
            pair<Node*, int > temp = q.front();
            Node* frontNode = temp.first;
            q.pop();
            
            int hd = temp.second;
            
            nodes[hd].push_back(frontNode->data);
            
            if (frontNode->left) 
                q.push(make_pair(frontNode->left, hd-1));
                
            if (frontNode->right)
                q.push(make_pair(frontNode->right, hd+1));
                
        }
        
        for (auto i : nodes)
            for (auto j : i.second)
                ans.push_back(j);
                    
        return ans;
    }
};
