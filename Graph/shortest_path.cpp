//? https://www.codingninjas.com/studio/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTab=0

//! T.C -> O(n + m)
//! S.C -> O(n)

#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	vector<vector<int>> adj(n+1);
	for (int i = 0; i < edges.size(); i++) {
		int u = edges[i].first;
		int v = edges[i].second;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<bool> visited(n+1);
	vector<int> parent(n+1);
	queue<int> q;

	q.push(s);
	visited[s] = true;
	parent[s] = -1;
	
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		
		for(auto nbr : adj[front]) {
			if (!visited[nbr]) {
				q.push(nbr);
				visited[nbr] = true;
				parent[nbr] = front;
			}
		}
	}
	
	vector<int> path;
	
	int curr = t;
	while (curr != -1) {
		path.push_back(curr);
		curr = parent[curr];
	}

	reverse(path.begin(), path.end());

	return path;
}
