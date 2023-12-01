//? https://practice.geeksforgeeks.org/problems/get-minimum-squares0538/1

//! T.C -> O(n*n)
//! S.C -> O(n)

//* Recursion + Memoization

#include <bits/stdc++.h> 
using namespace std;

class Solution{
    int solveMem(int n, vector<int> &dp) {
        // base case
        if (n == 0)
            return 0;
            
        if (dp[n] != -1)
            return dp[n];
        
        int ans = INT_MAX;
        for (int i = 1; i*i <= n; i++) {
            ans = min(ans, 1 + solveMem(n-(i*i), dp));
        }
        
        dp[n] = ans;
        return ans;
    }
	public:
	int MinSquares(int n)
	{
	    vector<int> dp(n+1, -1);
	    return solveMem(n, dp);
	}
};