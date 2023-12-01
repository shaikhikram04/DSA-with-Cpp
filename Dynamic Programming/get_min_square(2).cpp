//! T.C -> O(n)
//! S.C -> O(n)

//* Tabulation

#include <bits/stdc++.h>
using namespace std;

class Solution{
    int solveTab(int n) {
        vector<int> dp(n+1, INT_MAX);
        
        dp[0] = 0;
        dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], 1 + dp[i - (j*j)]);
            }
        }
        return dp[n];
    }
	public:
	int MinSquares(int n)
	{
	    return solveTab(n);
	}
};