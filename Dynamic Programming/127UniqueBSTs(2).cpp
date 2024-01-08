//! T.C -> O(n^2)
//! S.C -> O(n)

//* Tabulation

#include <bits/stdc++.h> 
using namespace std;

class Solution {
    int solveTab(int n) {
        //* create dp array
        vector<int> dp(n+1, 0);
        //* analyse and store base cases
        dp[0] = dp[1] = 1;

        //* solve for remaining cases
        for (int totalNode = 2; totalNode <= n; totalNode++) {
            //* iterate all node from 1 to totalNode
            for (int rootNode = 1; rootNode <= totalNode; rootNode++) {
                dp[totalNode] += dp[rootNode-1] * dp[totalNode-rootNode];
            }
        }

        return dp[n];
    }
public:
    int numTrees(int n) {
        return solveTab(n);
    }
};