//? https://www.codingninjas.com/studio/problems/0-1-knapsack_920542?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&leftPanelTabValue=PROBLEM

//! T.C -> O(n * maxWeight)
//! S.C -> O(n * maxWeight)

//* Recursion + Memoization

#include <bits/stdc++.h>
using namespace std;

int solveMem(vector<int> &weight, vector<int> &value, int capacity, int index, vector<vector<int>> &dp) {
	//* base case
	//* if only 1 item to steal, then just compare its weight with the knapsack capacity
	if (index == 0) {
		//* if thief can carry 0th item then return value of 0th item else return 0
		if (weight[0] <= capacity)
			return value[0];
		else	
			return 0;
	}

	//* in case, we already have result of curr recursive call 
	if (dp[index][capacity] != -1)
		return dp[index][capacity];

	int inc = 0;
	//* check can thief carry curr index item 
	if (weight[index] <= capacity)
		inc = value[index] + solveMem(weight, value, capacity-weight[index], index-1, dp);

	int exc = solveMem(weight, value, capacity, index-1, dp);

	//* store result in dp array
	dp[index][capacity] = max(inc, exc);
	
	return dp[index][capacity];
}

int knapsack(vector<int> &weight, vector<int> &value, int n, int maxWeight) 
{
	//* creating dp array in which row denote index and col denote capacity of knapsack
	vector<vector<int>> dp(n, vector<int> (maxWeight+1, -1));
	
	return solveMem(weight, value, maxWeight, n-1, dp);
}