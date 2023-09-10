//* using BFS

//! T.C -> O(n + m)
//! S.C -> O(n)

#include <bits/stdc++.h>
using namespace std;

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    //* creating adjacency list and indegree vector for each node
    vector<vector<int>> adj(n);
    vector<int> indegree(n);

    for (auto i : edges) {
        indegree[i.second-1]++;
        adj[i.first-1].push_back(i.second-1);
    }

    queue<int> q;
    int count = 0;
    
    //* push node with 0 inorder in queue
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    //* iterate until q is empty
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        //* increment count -> on traversing node
        count++;

        for (auto nbr : adj[front]) {
            //* decrement indegree
            indegree[nbr]--;
            //* push only if neighbour node has 0 indegree
            if (indegree[nbr] == 0)
                q.push(nbr);
        }
    }

    //* if count == n -> we traversed all node -> no cycle present
    return (count == n) ? 0 : 1;
}