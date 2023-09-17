

//! T.C -> O(V*log(V))
//! S.C -> O(V)


#include <bits/stdc++.h>
using namespace std; 

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

    // creating min heap 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minKey;

    // start from 1
    key[0] = 0;
    minKey.push({0, 0});

    while (!minKey.empty()) {
        // get minKey
        int u = minKey.top().second;
        minKey.pop();

        // mark as true
        MST[u] = true;
        
        // check neighbour
        for (auto nbr : adj[u]) {
            int v = nbr.first;
            int w = nbr.second;
            if (!MST[v] && key[v] > w) {
                key[v] = w;
                minKey.push({w, v});
                parent[v] = u;
            }
        }
        
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
 