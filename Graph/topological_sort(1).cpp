//? https://www.codingninjas.com/studio/problems/topological-sort_982938?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0\\

//* using DFS

//! T.C -> O(v + e)
//! S.C -> O(v)

#include <bits/stdc++.h>
using namespace std;

void solveDFS(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &s) {
    visited[node] = true;

    for (auto nbr : adj[node]) {
        if (!visited[nbr]) {
            solveDFS(nbr, adj, visited, s);
        }
    }

    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {

    //* make adjacency list
    vector<vector<int>> adj(v);
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    //* create visited array(to track is node is visited or not) and stack(store node in reverse order)
    vector<bool> visited(v);
    stack<int> s;

    for (int i = 0; i < v; i++) {
        if (!visited[i])
            solveDFS(i, adj, visited, s);
    }
    
    vector<int> ans;
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}