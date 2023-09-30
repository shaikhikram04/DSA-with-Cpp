//? https://www.codingninjas.com/studio/problems/bellmon-ford_2041977?leftPanelTab=0

//! T.C -> O(n * m)
//! S.C -> O(n)

#include <bits/stdc++.h>
using namespace std;

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int> dist(n+1,1e8);
    dist[src] = 0;
    
    int rep = n-1;
    while(rep--)
    {
      for(auto i: edges)
      {
          if(dist[i[0]] + i[2] < dist[i[1]])
          {
              dist[i[1]] = dist[i[0]] + i[2];
          }
      }
    }

    return dist;

}