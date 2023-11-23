//? https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0&leftPanelTabValue=PROBLEM

//! T.C -> O(n)
//! S.C -> O(n) + O(n)  ==>  O(n)

#include <bits/stdc++.h> 
using namespace std;

//* Recursion + Memoization

int solveRecMem(vector<int> &nums, int index, vector<int> &dp) {
    //* base case
    if (index >= nums.size()) {
        return 0;
    }

    if (dp[index] != -1) {
        return dp[index];
    }

    //* inclusion
    int incAns = nums[index] + solveRecMem(nums, index+2, dp);

    //* exclusion
    int excAns = solveRecMem(nums, index+1, dp);


    dp[index] = max(incAns, excAns);
    
    return dp[index];
    
}

int maximumNonAdjacentSum(vector<int> &nums){

    vector<int> dp(nums.size(), -1);

    return solveRecMem(nums, 0, dp);
}