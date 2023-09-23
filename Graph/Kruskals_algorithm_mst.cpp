//? https://www.codingninjas.com/studio/problems/minimum-spanning-tree_631769?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

//? Disjoint Set : https://www.geeksforgeeks.org/introduction-to-disjoint-set-data-structure-or-union-find-algorithm/

//! T.C -> O(e * log(e))
//! S.C -> O(v)


#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
}

void makeSet(vector<int> &parent, vector<int> &rank, int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node) {
    if (parent[node] == node)
        return node;

    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
    // find parent
    u = findParent(parent, u);
    v = findParent(parent, v);

    // comparing rank
    if (rank[u] < rank[v])
        parent[u] = v;

    else if (rank[v] < rank[u])
        parent[v] = u;

    else {
        parent[v] = u;
        rank[u]++;
    }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    vector<int> parent(n);
    vector<int> rank(n);
    // making disjoint set
    makeSet(parent, rank, n);

    // create a linear sorted data structure which hold weight, u, v
    sort(edges.begin(), edges.end(), cmp);

    int mstSum = 0;

    for (int i = 0; i < edges.size(); i++) {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);

        if (u != v) {
            unionSet(u, v, parent, rank);
            mstSum += edges[i][2];
        }
    }

    return mstSum;
}