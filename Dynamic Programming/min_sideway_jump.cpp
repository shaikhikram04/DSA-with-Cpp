//? https://leetcode.com/problems/minimum-sideway-jumps/description/

//! T.C -> O(3*n) => O(n)
//! S.C -> O(3*n) => O(n)

//* Recursion + Memoization

#include <bits/stdc++.h> 
using namespace std;

class Solution {
    int solveMem(vector<int>& obstacles, int pos, int lane,vector<vector<int>>& dp) {
        //* base case : If frog reach at (n-1)th position then return 0
        if (pos == obstacles.size()-1)
            return 0;

        //* return ans if already have
        if (dp[pos][lane] != -1)
            return dp[pos][lane];

        //* If no obstacle front of frog
        if (obstacles[pos+1] != lane) {
            return solveMem(obstacles, pos+1, lane, dp);
        }
        else {
            //* If obstacle front of frog
            int ans = INT_MAX;
            //* check for each lane
            for (int l = 1; l <= 3; l++) {
                //* if lane is itself of lane have an obstacle then skip that lane
                if (l != lane && obstacles[pos] != l)
                    ans = min(ans, 1 + solveMem(obstacles, pos+1, l, dp));
            }

            //* store ans in dp array
            return dp[pos][lane] = ans;
        }
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>> dp(obstacles.size()-1, vector<int> (4, -1)); 
        return solveMem(obstacles, 0, 2, dp);
    }
};