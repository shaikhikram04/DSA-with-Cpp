//? https://www.codingninjas.com/studio/problems/prim-s-mst_1095633?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

//! T.C -> O(V^2)
//! S.C -> O(V)

#include <bits/stdc++.h>
using namespace std; 

int minKey(vector<int> &key, vector<bool> &MST, int n) {
    int miniIndex = -1;
    int mini = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (key[i] < mini && !MST[i]) {
            mini = key[i];
            miniIndex = i;
        }
    }
    return miniIndex;
}

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // making adjacency list
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u = g[i].first.first - 1;
        int v = g[i].first.second - 1;
        int cost = g[i].second;
        adj[u].push_back({v, cost});
        adj[v].push_back({u, cost}); 
    }
    vector<int> key(n, INT_MAX), parent(n, -1);
    vector<bool> MST(n);

    // start from 1
    key[0] = 0;

    // find max key which is not operated(MST->false)
    int u = 0;
    while (u >= 0) {
        // mark as true
        MST[u] = true;
        
        // check neighbour
        for (auto nbr : adj[u]) {
            int v = nbr.first;
            int w = nbr.second;
            if (!MST[v] && key[v] > w) {
                key[v] = w;
                parent[v] = u;
            }
        }

        u = minKey(key, MST, n);
    }
    vector<pair<pair<int, int>, int>> ans;
    for (int i = 1; i < n; i++) {
        int u = parent[i] + 1;
        int v = i + 1;
        int w = key[i];
        ans.push_back({{u, v}, w});
    }
    return ans;
}
 