//! T.C -> O(3*n) => O(n)
//! S.C -> O(3*n) => O(n)

//* Tabulation

#include <bits/stdc++.h> 
using namespace std;

class Solution {

    int solveTab(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> dp(4, vector<int> (n, INT_MAX));

        for (int i = 0; i < 4; i++) {
            dp[i][n-1] = 0;
        }

        for (int i = n-2; i >= 0; i--) {
            for (int lane = 1; lane <= 3; lane++) {
                if (obstacles[i] != lane) {
                    if (obstacles[i+1] != lane) {
                        dp[lane][i] = dp[lane][i+1];
                    }
                    else {
                        for (int l = 1; l <= 3; l++) {
                            if (l != lane && obstacles[i] != l) {
                                dp[lane][i] = min(dp[lane][i] , 1 + dp[l][i+1]);
                            }
                        }
                    }
                }
            }
        }

        return dp[2][0];
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        return solveTab(obstacles);
    }
};