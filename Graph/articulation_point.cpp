//? https://www.codingninjas.com/studio/library/articulation-points-in-a-graph

//* Brute Force Approach

//! T.C -> O(v*(v + e))
//! S.C -> O(v)

#include <bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int ignoreNode, vector<vector<int>> &adj, vector<bool> &visited) {

    visited[node] = true;
    for (auto nbr : adj[node]) {
        if (!visited[nbr] && nbr != ignoreNode)
            dfs(nbr, ignoreNode, adj, visited);
    }

}

bool isAllTrue(vector<bool> &visited, int N) {
    for (int i = 0; i < N; i++) {
        if (!visited[i])
            return false;
    }
    return true;
}

vector<int> articulationPoint(int N, vector<vector<int>> &edges, int E) {

    vector<int> result;

    vector<vector<int>> adj(N);
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < N; i++) {
        vector<bool> visited(N);

        visited[i] = true;
        dfs(adj[i][0], i, adj, visited);

        if (!isAllTrue(visited, N)) {
            result.push_back(i);
        }
    }
    return result;
}

int main(){
    
    int N, E;
    cin >> N >> E;

    vector<vector<int>> edges(E);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        edges[i].push_back(u);
        edges[i].push_back(v);
    }

    vector<int> result = articulationPoint(N, edges, E);

    cout << "\nArticulation Points" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    } 
    cout << endl;
    
    
    return 0;
}