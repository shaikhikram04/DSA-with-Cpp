//? https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/

//! T.C -> O(n*target)
//! S.C -> O(n*target)

//* Recursion + Memoization

#include <bits/stdc++.h> 
using namespace std;

#define mod 1000000007

class Solution {

    int solveMem(int n, int k, int target, vector<vector<int>>& dp) {
        //* if there is no dice remaining
        if (n == 0) {
            //* And we complete target that means it is a possible way so return 1
            if (target == 0)
                return 1;
            
            //* else target is not completed that means it is not possible way so return 0
            return 0;
        }

        if (dp[n][target] != -1)
            return dp[n][target];

        //* assign ans = 0 to store no. of possible ways if no. of dice is n and target is target
        int ans = 0;

        //* check for all possible faces of dice(from 1 to k also it should be less than or equal to target) which can make a target
        //* accumulate its result in ans
        for (int i = 1; i <= k && i <= target; i++) {
            ans = (ans + solveMem(n-1, k, target-i, dp)) % mod;
        }

        //* return ans
        return dp[n][target] = ans % mod;
    }

public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int> (target+1, -1));

        return solveMem(n, k, target, dp);
    }
};