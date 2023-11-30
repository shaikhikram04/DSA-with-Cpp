//! T.C -> O(n * maxWeight)
//! S.C -> O(2*maxWeight)

//* Space Optimization

#include <bits/stdc++.h> 
using namespace std;

int solveSO(vector<int> &weight, vector<int> &value, int n, int maxWeight) {
	vector<int> prev(maxWeight+1, 0);
	vector<int> curr(maxWeight+1, 0);

	for (int cap = 0; cap <= maxWeight; cap++) {
		if (weight[0] <= cap)
			prev[cap] = value[0];
	}

	for (int index = 1; index < n; index++) {
		for (int cap = 0; cap <= maxWeight; cap++) {

			int inc = 0;
			if (weight[index] <= cap) {
				inc = value[index] + prev[cap-weight[index]];
			}
			
			int exc = prev[cap];

			curr[cap] = max(inc, exc); 
		}
		prev = curr;
	}

	return prev[maxWeight];
}


int knapsack(vector<int> &weight, vector<int> &value, int n, int maxWeight) 
{
	return solveSO(weight, value, n, maxWeight);
}