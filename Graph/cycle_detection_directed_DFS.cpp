//? https://www.codingninjas.com/studio/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=0

//! T.C -> O(n + m)
//! S.C -> O(n)

#include <bits/stdc++.h>
using namespace std;

bool isCyclicDFS(int node, unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, bool> &DFSvisited)
{

    visited[node] = true;
    DFSvisited[node] = true;

    for (auto nbr : adj[node])
    {
        if (!visited[nbr])
        {
            if (isCyclicDFS(nbr, adj, visited, DFSvisited))
                return true;
        }
        else if (DFSvisited[nbr])
            return true;
    }

    //* back tracking
    DFSvisited[node] = false;

    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    //* create adjacency list
    unordered_map<int, vector<int>> adj;

    for (auto i : edges)
    {
        adj[i.first].push_back(i.second);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> DFSvisited;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (isCyclicDFS(i, adj, visited, DFSvisited))
                return 1;
        }
    }

    return 0;
}