//* using kahn's algorithm (BFS)

//! T.C -> O(v + e)
//! S.C -> O(v)

#include <bits/stdc++.h>
using namespace std; 

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<vector<int>> adj(v);
    vector<int> indegree(v);
    
    for (int i = 0; i < e; i++) {
        int a = edges[i][0];
        int b = edges[i][1];
        
        indegree[b]++;
        adj[a].push_back(b);
    }
    
    
    queue<int> q;
    vector<int> ans;

    for (int i = 0; i < v; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }
        
    while (!q.empty()) {
        int front = q.front();
        ans.push_back(front);
        q.pop();
        
        for (auto nbr : adj[front]) {
            indegree[nbr]--;
            if (indegree[nbr] == 0) {
                q.push(nbr);
            }
        }
    }
    

    return ans;
}