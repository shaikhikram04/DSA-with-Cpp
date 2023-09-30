//? https://www.codingninjas.com/studio/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151?leftPanelTab=0

//! T.C -> O(v + e)
//! S.C -> O(v + e)  -> for transpose of a graph

#include <bits/stdc++.h>
using namespace std;

void topologicalSort(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &ans) {
	visited[node] = true;
	
	for (auto nbr : adj[node]) {
		if (!visited[nbr])
			topologicalSort(nbr, adj, visited, ans);
	}

	ans.push(node);
}

void dfs(int node, vector<vector<int>> &transpose, vector<bool> &visited) {
	visited[node] = true;
	
	for (auto nbr : transpose[node]) {
		if (!visited[nbr])
			dfs(nbr, transpose, visited);
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	//* make adj list 
	vector<vector<int>> adj(v);
	for (int i = 0; i < edges.size(); i++) {
		int u = edges[i][0];
		int v = edges[i][1];
		
		adj[u].push_back(v);
	}
	
	//* topological sort
	stack<int> topo;
	vector<bool> visited(v);
	for (int i = 0; i < v; i++) {
		if (!visited[i])
			topologicalSort(i, adj, visited, topo);
	}
	
	//* create a transpose graph
	vector<vector<int>> transpose(v);
	for (int i = 0; i < v; i++) {
		for (auto nbr : adj[i]) 
			transpose[nbr].push_back(i);
	}

	
	//* dfs call for count SCC
	int sccCnt = 0;
	for (int i = 0; i < v; i++)
		visited[i] = false;
	
	while (!topo.empty()) {
		int top = topo.top();
		topo.pop();
		if (!visited[top]) {
			dfs(top, transpose, visited);
			sccCnt++;
		}
	}
	
	return sccCnt;
}