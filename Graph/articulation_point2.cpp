
//* Using DFS


//! T.C -> O(v + e)
//! S.C -> O(v)

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int> &disc, vector<int> &low, vector<bool> &visited, vector<vector<int>> &adj, 
            vector<bool> &ap, int &timer) {

    visited[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0;
    for (auto nbr : adj[node]) {
        if (nbr != parent) {
            if (!visited[nbr]) {
                dfs(nbr, node, disc, low, visited, adj, ap, timer);
                low[node] = min(low[node], low[nbr]);

                //* check node is articulation point
                if (low[nbr] >= disc[node] && parent != -1) {
                    ap[node] = true;
                }
                child++;
            }
            else {
                //* back edge
                low[node] = min(low[node], disc[nbr]);
            }
        }
    }
    if (parent == -1 && child > 1)
        ap[node] = true;
}

vector<int> getArticutionPoint(int N, vector<vector<int>> &edges, int E) {
    vector<int> result;

    //* adj list
    vector<vector<int>> adj(N);
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(N, -1);
    vector<int> low(N, -1);
    vector<bool> visited(N);
    vector<bool> ap(N);

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            dfs(i, -1, disc, low, visited, adj, ap, timer);
        }
    }

    for (int i = 0; i < N; i++) {
        if (ap[i])
            result.push_back(i);
    }

    return result;
}

int main() {

    int N, E;
    cin >> N >> E;

    vector<vector<int>> edges(E);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        edges[i].push_back(u);
        edges[i].push_back(v);
    }


    vector<int> ap = getArticutionPoint(N, edges, E);
    
    cout << "articulation points are : ";
    for (auto i : ap)
        cout << i << ", ";
    cout << endl;


    return 0;
}
/*
5 5
0 1
0 2
2 3
2 4
3 4
*/