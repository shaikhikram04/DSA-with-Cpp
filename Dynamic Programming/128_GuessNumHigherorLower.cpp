//? https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/

//! T.C -> O(n^3)
//! S.C -> O(n^3)

//* Recursion + Memoization

#include <bits/stdc++.h> 
using namespace std;


class Solution {
    int solveMem(int start, int end,vector<vector<int>>& dp) {
        //* If there is only 1 or no element in between start and end Then return 0
        if (end - start <= 0)
            return 0;

        //* If ans of range already given then return the ans
        if (dp[start][end] != -1)
            return dp[start][end];

        //* To store minimum ans
        int minAns = INT_MAX;
        //* Iterate each element between range
        //* Check each number than if we guess that number then what will be the ans
        for (int i = start; i <= end; i++) {
            //* If the correct number to guess in greater
            int higher = solveMem(i+1, end, dp);
            //* If the correct number to guess in lower
            int lower = solveMem(start, i-1, dp);

            //* store the answer
            int ans = max(higher, lower) + i;

            //* Store minimal ans to return
            minAns = min(minAns, ans);
        }

        return dp[start][end] = minAns;
    }


public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return solveMem(1, n, dp);
    }
};