//? https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

//! T.C -> O(n*n)
//! S.C -> O(n*n)

//* Recursion + Memoization

#include <bits/stdc++.h> 
using namespace std;

class Solution
{
    int solveRec(int n, int a[], int curr, int prev, vector<vector<int>> &dp) {
        //* base case
        if (curr >= n)
            return 0;
            
        if (dp[curr][prev+1] != -1)
            return dp[curr][prev+1];
        
        //* include
        int inc = 0;
        //! if curr val make sequence strictly increasing 
        //! OR there is no value inserted in sequence (i.e. prev == -1) then only we include.
        if (prev == -1 || a[curr] > a[prev])
            inc = 1 + solveRec(n, a, curr+1, curr, dp);
        
        //* exclude
        int exc = solveRec(n, a, curr+1, prev, dp);
        
        //* since we start prev from -1 so we need to store ans in (prev+1) {Initially prev = -1 then prev+1 = 0}
        return dp[curr][prev+1] = max(inc, exc);
    }
    
public:

    int longestSubsequence(int n, int a[])
    {
        vector<vector<int>> dp(n, vector<int> (n, -1));
        //* prev start from -1 because there is no previous index for currIndex-->0 
        return solveRec(n, a, 0, -1, dp);
    }
};