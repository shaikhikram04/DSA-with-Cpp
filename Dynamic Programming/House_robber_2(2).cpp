//! T.C -> O(n)
//! S.C -> O(n)

//* Tabulation

#include <bits/stdc++.h> 
using namespace std;

class Solution {
    int solveTab(vector<int> &nums, int n, int index) {
        vector<int> dp(n, -1);

        //* analyse and store base case
        dp[index] = nums[index];
        
        for (int i = index+1; i < n; i++) {
            int inc = nums[i];
            if (i-2 >= index)
                inc += dp[i-2];
                
            int exc = dp[i-1];
            dp[i] = max(inc, exc);
        }

        return dp[n-1];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        //* for only one house
        if (n == 1)
            return nums[0];

        //* if first inc and last exc
        int firstInc = solveTab(nums, n-1, 0);

        //* if first exc and last inc
        int lastInc = solveTab(nums, n, 1);

        return max(firstInc, lastInc);
    }
};