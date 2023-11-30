//! T.C -> O(n * maxWeight)
//! S.C -> O(n * maxWeight)

//* Tabulation

#include <bits/stdc++.h>
using namespace std;

int solveTab(vector<int> &weight, vector<int> &value, int n, int maxWeight) {

	//* step 1: create dp array
	vector<vector<int>> dp(n, vector<int> (maxWeight+1, 0));

	//* step 2: analyse and store base case
	for (int capacity = 0; capacity <= maxWeight; capacity++) {
		if (weight[0] <= capacity)
			dp[0][capacity] = value[0];
	}

	//* step 3: solve for remaining 
	for (int index = 1; index < n; index++) {
		for (int capacity = 0; capacity <= maxWeight; capacity++) {
			
			int inc = 0;
			if (weight[index] <= capacity)
				inc = value[index] + dp[index-1][capacity-weight[index]];

			int exc = dp[index-1][capacity];

			dp[index][capacity] = max(inc, exc);
		}
	}


	return dp[n-1][maxWeight];
}


int knapsack(vector<int> &weight, vector<int> &value, int n, int maxWeight) 
{
	return solveTab(weight, value, n, maxWeight);
}