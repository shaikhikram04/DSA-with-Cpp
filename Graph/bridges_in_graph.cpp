//? https://www.codingninjas.com/studio/problems/bridges-in-graph_893026?leftPanelTab=0

//! T.C -> O(v + e)
//! S.C -> O(v)


#include <bits/stdc++.h>
using namespace std;


void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, 
        vector<bool> &visited, vector<vector<int>> &result, vector<vector<int>> &adj) {
    
    visited[node] = true;
    disc[node] = low[node] = timer++;

    for (auto nbr : adj[node]) {
        if (nbr != parent) {
            if (!visited[nbr]) {
                dfs(nbr, node, timer, disc, low, visited, result, adj);
                low[node] = min(low[node], low[nbr]);
                // check edege is bridge
                if (low[nbr] > disc[node]) {
                    result.push_back({node, nbr});
                }
            }
            else {
                //* back edge
                low[node] = min(low[node], disc[nbr]);
            }
        }
    }

}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    
    // make adjacency list
    vector<vector<int>> adj(v);
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v1 = edges[i][1];

        adj[u].push_back(v1);
        adj[v1].push_back(u);
    }

    //* create 4 linear DS
    vector<int> disc(v, -1), low(v, -1);
    vector<bool> visited(v, false);
    int parent = -1;

    int timer = 0;

    vector<vector<int>> result;
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            dfs(i, parent, timer, disc, low, visited, result, adj);
        }
    }

    return result;
}
