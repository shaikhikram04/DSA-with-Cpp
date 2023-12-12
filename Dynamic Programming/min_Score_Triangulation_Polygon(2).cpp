//! T.C -> O(n*n)
//! S.C -> O(n*n)

//* Tabulation

#include <bits/stdc++.h> 
using namespace std;

class Solution {
    int solveTab(vector<int>& v, int n) {
        //* create dp array
        vector<vector<int>> dp(n-1, vector<int> (n, 0));

        //* solve for remaining cases (i.e for upper triangle)
        for (int i = n-3; i >= 0; i--) {
            for (int j = i+2; j < n; j++) {
                dp[i][j] = INT_MAX;
                for (int k = i+1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], v[i]*v[j]*v[k] + dp[i][k] + dp[k][j]);
                }
            }
        }

        return dp[0][n-1];
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        return solveTab(values, n);
    }
};

