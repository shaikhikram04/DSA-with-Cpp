// https://practice.geeksforgeeks.org/problems/burning-tree/1

#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    
    Node* createParentMapping (map<Node*, Node*> &nodeToParent, Node* root, int target) {
        queue<Node*> q;
        Node* targetNode = NULL;
        q.push(root);
        nodeToParent[root] = NULL;
        
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            
            if(temp->data == target)
                targetNode = temp;
            
            if(temp->left) {
                nodeToParent[temp->left] = temp;
                q.push(temp->left);
            }
            
            if(temp->right) {
                nodeToParent[temp->right] = temp;
                q.push(temp->right);
            }
        }
        return targetNode;
    }
    
    int burnTree(Node* targetNode, map<Node*, Node*> nodeToParent) {
        map<Node*, bool> visited;
        queue<Node*> q;
        
        q.push(targetNode);
        visited[targetNode] = true;
        
        int ans = 0;
        
        while (!q.empty()) {
            bool flag = 0;
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                Node* front = q.front();
                q.pop();
                
                if(front->left && !visited[front->left]) {
                    flag = 1;
                    q.push(front->left);
                    visited[front->left] = 1;
                }
                
                if (front->right && !visited[front->right]) {
                    flag = 1;
                    q.push(front->right);
                    visited[front->right] = 1;
                }
                
                if (nodeToParent[front] && !visited[nodeToParent[front]]) {
                    flag = 1;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = 1;
                }
            }
            
            if (flag) {
                ans++;
            }
                
        }
        return ans;
    }
    
  public:
    int minTime(Node* root, int target) 
    {
        
        map<Node*, Node*> nodeToParent;
        Node* targetNode = createParentMapping(nodeToParent, root, target);
        
        int ansTime = burnTree(targetNode, nodeToParent);
        
        return ansTime;
    }
};