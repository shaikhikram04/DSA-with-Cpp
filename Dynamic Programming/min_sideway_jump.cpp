//? https://leetcode.com/problems/minimum-sideway-jumps/description/

//! T.C -> O(3*n) => O(n)
//! S.C -> O(3*n) => O(n)

//* Recursion + Memoization

#include <bits/stdc++.h> 
using namespace std;

class Solution {
    int solveRec(vector<int>& obstacles, int i, int lane,vector<vector<int>>& dp) {
        if (i == obstacles.size()-1)
            return 0;

        if (dp[i][lane] != -1)
            return dp[i][lane];

        
        if (obstacles[i+1] != lane) {
            return solveRec(obstacles, i+1, lane, dp);
        }
        else {
            int ans = INT_MAX;
            for (int l = 1; l <= 3; l++) {
                if (l != lane && obstacles[i] != l)
                    ans = min(ans, 1 + solveRec(obstacles, i+1, l, dp));
            }
            return dp[i][lane] = ans;
        }
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>> dp(obstacles.size()-1, vector<int> (4, -1)); 
        return solveRec(obstacles, 0, 2, dp);
    }
};