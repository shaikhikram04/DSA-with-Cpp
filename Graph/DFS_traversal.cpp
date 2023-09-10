// https://www.codingninjas.com/studio/problems/dfs-traversal_630462?leftPanelTab=0


// T.C -> O(n + m)
// S.C -> O(n + m)


#include <bits/stdc++.h>
using namespace std;


void createAdjList(int E, vector<vector<int>> &edges, unordered_map<int, list<int>> &adjList) {

    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void dfs(int i, unordered_map<int, list<int>> &adjList, int visited[], vector<int> &ans) {

    ans.push_back(i);
    visited[i] = 1;

    for (auto it: adjList[i]) {
        if (visited[it] == 0)
            dfs(it, adjList, visited, ans);
    }
}
 
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adjList;

    createAdjList(E, edges, adjList);

    int visited[V] = {0};
    vector<vector<int>> ans;

    for (int i = 0; i < V; i++) {
        if (visited[i] == 0) {
            vector<int> temp;
            dfs(i,adjList, visited, temp);
            ans.push_back(temp);
        }
    }

    return ans;
}