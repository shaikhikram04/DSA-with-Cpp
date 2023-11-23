//? https://leetcode.com/problems/house-robber-ii/submissions/1100889558/

//! T.C -> O(n)
//! S.C -> O(n)

//* Recursion + Memoization

#include <bits/stdc++.h> 
using namespace std;

class Solution {
    int solveRecMem(vector<int> &valueInHouse, int n,vector<int> &dp, int index) {
        //* base case
        if (index >= n)
            return 0;

        if (dp[index] != -1)
            return dp[index];

        
        //* inclusion
        int inc = valueInHouse[index] + solveRecMem(valueInHouse, n, dp, index+2);

        //* exclusion
        int exc = solveRecMem(valueInHouse, n, dp, index+1);

        return dp[index] = max(inc, exc);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        //* for only one house
        if (n == 1)
            return nums[0];

        vector<int> dp(n, -1);

        //* if first inc and last exc
        int firstInc = solveRecMem(nums, n-1, dp, 0);

        for (int i = 0; i < n; i++)
            dp[i] = -1;

        //* if first exc and last inc
        int lastInc = solveRecMem(nums, n, dp, 1);

        return max(firstInc, lastInc);
    }
};