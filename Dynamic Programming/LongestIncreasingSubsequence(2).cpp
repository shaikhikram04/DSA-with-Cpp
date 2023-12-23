//! T.C -> O(n*n)
//! S.C -> O(n*n)

//* Tabulation

#include <bits/stdc++.h> 
using namespace std;


class Solution
{
    
    int solveTab(int n, int a[]) {
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        
        for (int curr = n-1; curr >= 0; curr--) {
            for (int prev = curr-1; prev >= -1; prev--) {
                //* include
                int inc = 0;
                if (prev == -1 || a[curr] > a[prev])
                    inc = 1 + dp[curr+1][curr+1]; //* since we prev ans in prev+1 so ans of dp[curr+1][curr] is stored in dp[curr+1][curr+1] 
                
                //* exclude
                int exc = dp[curr+1][prev+1];    //* since we prev ans in prev+1 so, ans of dp[curr+1][prev] is stored in dp[curr+1][prev+1] 
                
                
                dp[curr][prev+1] = max(inc, exc);
            }
        }
        
        return dp[0][0];
    }
    
    public:
    int longestSubsequence(int n, int a[])
    {
        return solveTab(n, a);
    }
};