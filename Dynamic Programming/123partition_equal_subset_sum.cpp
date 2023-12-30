//? https://leetcode.com/problems/partition-equal-subset-sum/description/

//! T.C -> O(n)
//! S.C -> O(n)

//* Recursion + Memoization

#include <bits/stdc++.h> 
using namespace std;


class Solution {

    bool solveMem(vector<int>& nums,int index, int tarSum, vector<vector<int>>& dp) {
        //* if we reach at target sum then return true
        if (tarSum == 0)
            return 1;

        //* if index goes out of the array OR targetSum is in -ve that means we cant make tarSum so, return false
        if (tarSum < 0 || index >= nums.size()) 
            return 0;

        if (dp[index][tarSum] != -1)
            return dp[index][tarSum];

        
        //* if after include curr element ans is true then return true
        if (solveMem(nums, index+1, tarSum-nums[index], dp) == 1)
            return dp[index][tarSum] = 1;
        

        //* if after exclude curr element ans is true then return true
        if (solveMem(nums, index+1, tarSum, dp) == 1)
            return dp[index][tarSum] = 1;

        //* otherwise return false
        return dp[index][tarSum] = 0;
    }
public:
    bool canPartition(vector<int>& nums) {
        //* find sum of array
        int sum = 0;
        for (int i : nums)
            sum += i;

        //* total sum is odd => we cant break array into 2 equal part so return false
        if (sum%2)
            return false;

        //* Solve if sum is even
        vector<vector<int>> dp(nums.size(), vector<int> (sum/2+1, -1));
        return solveMem(nums, 0, sum/2, dp);
    }   
};