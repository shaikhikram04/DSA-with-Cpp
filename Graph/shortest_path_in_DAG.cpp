//? https://www.codingninjas.com/studio/problems/shortest-path-in-dag_8381897?leftPanelTab=0


//! T.C -> O(n + m)
//! S.C -> O(n)

#include <bits/stdc++.h>
using namespace std;


void topologicalSort(int node, vector<bool> &visited, stack<int> &s, vector<vector<pair<int, int>>> &adj) {
    visited[node] = true;

    for (auto nbr : adj[node]) {
        if (!visited[nbr.first]) {
            topologicalSort(nbr.first, visited, s, adj);
        }
    }    

    s.push(node);
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    //* create adjacency list for directed weighted graph
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int cost = edges[i][2];

        adj[u].push_back({v, cost});
    }

    //* create topological sort of graph
    vector<bool> visited(n);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            topologicalSort(i, visited, s, adj);
    }

    vector<int> dist(n, -1);
    dist[0] = 0;
    while (!s.empty()) { 
        int top = s.top();
        s.pop();

        if (dist[top] >= 0) {
            for (auto nbr : adj[top]) {
                if (dist[nbr.first] == -1 ||  dist[nbr.first] > dist[top] + nbr.second)
                    dist[nbr.first] = dist[top] + nbr.second;
            }
        }
    }

    return dist;
}
