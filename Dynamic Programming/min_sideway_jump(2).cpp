//! T.C -> O(3*n) => O(n)
//! S.C -> O(3*n) => O(n)

//* Tabulation

#include <bits/stdc++.h> 
using namespace std;

class Solution {

    int solveTab(vector<int>& obstacles) {
        int n = obstacles.size();
        //* create dp array of 4 row(indicate lane) and n column(indicate position)
        vector<vector<int>> dp(4, vector<int> (n, INT_MAX));

        //* initialize all destination lane as 0
        for (int i = 0; i < 4; i++) {
            dp[i][n-1] = 0;
        }


        for (int i = n-2; i >= 0; i--) {
            for (int lane = 1; lane <= 3; lane++) {
                //* if lane has no obstacle then 
                if (obstacles[i] != lane) {
                    //* If no obstacle front of frog
                    if (obstacles[i+1] != lane) {
                        dp[lane][i] = dp[lane][i+1];
                    }
                    else {
                        //* If obstacle front of frog
                        //* check for each lane
                        for (int l = 1; l <= 3; l++) {
                            //* if lane is itself of lane have an obstacle then skip that lane
                            if (l != lane && obstacles[i] != l) {
                                //* store minimum value in dp array
                                dp[lane][i] = min(dp[lane][i] , 1 + dp[l][i+1]);
                            }
                        }
                    }
                }
            }
        }

        //* return ans when frog at 0th position and 2nd lane
        return dp[2][0];
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        return solveTab(obstacles);
    }
};