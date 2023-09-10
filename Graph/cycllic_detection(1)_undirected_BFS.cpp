//? https://www.codingninjas.com/studio/problems/cycle-detection-in-undirected-graph_1062670?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

//! T.C -> O(n + m)
//! S.C -> O(n)


#include <bits/stdc++.h>
using namespace std;

void createAdjList(vector<vector<int>>& edges, int m, unordered_map<int, list<int>> &adj) {
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

bool isCyclicBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj) {

    unordered_map<int, int> parent;
    parent[src] = -1;

    visited[src] = true;

    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (auto nbr : adj[front]) {
            if (!visited[nbr]) {
                q.push(nbr);
                visited[nbr] = true;
                parent[nbr] = front;
            } 
            else if (parent[front] != nbr)
                return true;
            
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int, list<int>> adj;
    // creating adjacency list
    createAdjList(edges, m, adj);
    // tracking visited node
    unordered_map<int, bool> visited;

    //* handle for each component
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            bool isCyclic = isCyclicBFS(i, visited, adj);

            if (isCyclic)
                return "Yes";
        }
    }

    return "No";
}
  