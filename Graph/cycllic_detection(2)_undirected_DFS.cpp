

//! T.C -> O(n + m)
//! S.C -> O(n)


#include <bits/stdc++.h>
using namespace std;

//* creating adjacency list using map
void createAdjList(vector<vector<int>>& edges, int n, int m, unordered_map<int, list<int>> &adj) {
    
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

bool isCyclicDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, int parent) {
    //* mark curr node as visited
    visited[node] = true;

    //* iterate for each neighbour of node
    for (auto nbr : adj[node]) {
        //* if neighbour is not visited 
        if (!visited[nbr]) {
            //* recersive call
            if (isCyclicDFS(nbr, visited, adj, node))
                return true; //* if there exist a cycle(get from recersive call) then return true
        }
        //? if not visited and also parent != neighbour (i.e. not travel already traveled path)
        else if (parent != nbr) {
            //? that mean cycle present -> return true
            return true;
        }
    }

    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int, list<int>> adj;
    createAdjList(edges, n, m, adj);
    unordered_map<int, bool> visited;
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (isCyclicDFS(i, visited, adj, -1))
                return "Yes";
        }
    }

    return "No";
}
