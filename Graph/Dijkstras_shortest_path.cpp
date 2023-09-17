//? https://www.codingninjas.com/studio/problems/dijkstra-s-shortest-path_920469?leftPanelTab=0

//! T.C -> O((V + E) log(v))
//! S.C -> O(V^2)


#include <bits/stdc++.h>
using namespace std;


vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector<vector<pair<int, int>>> adj(vertices);
    for (int i = 0; i < edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int cost = vec[i][2];

        adj[u].push_back({v, cost}); 
        adj[v].push_back({u, cost});
    }
    vector<int> dis(vertices, INT_MAX);
    set<pair<int, int>> s;

    dis[source] = 0;
    s.insert({0,source});

    while (!s.empty()) {
        pair<int, int> top = *s.begin();
        s.erase(s.begin());

        for (auto nbr : adj[top.second]) {
            if (dis[nbr.first] > nbr.second + top.first) {
                auto record = s.find({dis[nbr.first], nbr.first});
                //* if record found then erase it
                if (record != s.end())
                    s.erase(record);

                //* update distance and insert record into set
                dis[nbr.first] = nbr.second + top.first;
                s.insert({dis[nbr.first], nbr.first});
            }
        }
    }

    return dis;
}
 