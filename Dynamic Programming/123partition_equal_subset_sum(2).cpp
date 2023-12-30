//! T.C -> O(n*target)
//! S.C -> O(n*target)

//* Tabulation

#include <bits/stdc++.h> 
using namespace std;

class Solution {

    bool solveTab(vector<int>& nums) {
        //* find sum of array
        int sum = 0;
        for (int i : nums)
            sum += i;

        //* if total sum is odd
        if (sum & 1)
            return false;

        //* Solve if sum is even
        int n = nums.size();
        vector<vector<bool>> dp(n+1, vector<bool> (sum/2+1, false));
        
        //* analyse and store base case
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        //* solve for remaining cases
        for (int index = n-1; index >= 0; index--) {
            int temp = nums[index];
            for (int tarSum = 1; tarSum <= sum/2; tarSum++) {
                //* if after include curr element ans is true store ans in dp array and skip the exclude part
                if (tarSum-temp >= 0 && dp[index+1][tarSum-temp]) {
                    dp[index][tarSum] = true;
                    continue;
                }

                //* if after exclude curr element ans is true store it in dp array
                if (dp[index+1][tarSum]) {
                    dp[index][tarSum] = true;
                }
            }
        }
        //* return ans when index = 0 AND tarSum = sum/2
        return dp[0][sum/2];
    }

public:
    bool canPartition(vector<int>& nums) {
        return solveTab(nums);
    }   
};