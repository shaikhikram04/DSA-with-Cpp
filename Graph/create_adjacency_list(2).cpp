// https://www.codingninjas.com/studio/problems/create-a-graph-and-print-it_1214551?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1


// T.C -> O(max(m,n))
// S.C -> O(n*n)


#include <bits/stdc++.h>
using namespace std;


vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    vector<vector<int>> ans(n);
    
    for (int i = 0; i < n; i++) {
        ans[i].push_back(i);
    }

    for (int i = 0; i < m; i++) {
        int r = edges[i][0];
        int c = edges[i][1];

        ans[r].push_back(c);
        ans[c].push_back(r);
    }

    return ans;
}