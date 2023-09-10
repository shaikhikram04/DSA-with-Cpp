//? https://www.codingninjas.com/studio/problems/bfs-in-graph_973002?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0


//! T.C -> O(n + m)
//! S.C -> O(n)


#include <bits/stdc++.h>
using namespace std;

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){

    queue<int> q;
    int visited[n] = {0};
    vector<int> ans;

    q.push(0);
    visited[0] = 1;

    while (!q.empty()) {
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for (auto i : adj[front]) {
            if (visited[i] == 0) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    
    return ans;
}