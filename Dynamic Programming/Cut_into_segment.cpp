//? https://www.codingninjas.com/studio/problems/cut-into-segments_1214651?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&leftPanelTabValue=PROBLEM

//! T.C -> O(n)
//! S.C -> O(n)

//* Recursion + Memoization

#include <bits/stdc++.h> 
using namespace std;

int solveMem(int n, int x, int y, int z, vector<int> &dp) {
	//* base case
	if (n == 0)
		return 0;

	if (dp[n] != -1)
		return dp[n];
	
	int ans = INT_MIN;

	if (x <= n) 
		ans = max(ans,1 + solveMem(n-x, x, y, z, dp));

	if (y <= n) 
		ans = max(ans,1 + solveMem(n-y, x, y, z, dp));

	if (z <= n) 
		ans = max(ans,1 + solveMem(n-z, x, y, z, dp));
	

	dp[n] = ans;

	return dp[n];
}

int cutSegments(int n, int x, int y, int z) {

	vector<int> dp(n+1, -1);

	int ans = solveMem(n, x, y, x, dp);
	if (ans < 0)
		return 0;

	return ans;
}