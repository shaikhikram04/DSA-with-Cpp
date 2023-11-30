//! T.C -> O(n * maxWeight)
//! S.C -> O(maxWeight)

//* Space Optimization

#include <bits/stdc++.h> 
using namespace std;


int solveSO(vector<int> &weight, vector<int> &value, int n, int maxWeight) {
	vector<int> curr(maxWeight+1, 0);

	for (int cap = 0; cap <= maxWeight; cap++) {
		if (weight[0] <= cap)
			curr[cap] = value[0];
	}
	
	for (int index = 1; index < n; index++) {
		for (int cap = maxWeight; cap >= 0; cap--) {

			int inc = 0;
			if (weight[index] <= cap) {
				inc = value[index] + curr[cap-weight[index]];
			}
			
			int exc = curr[cap];

			curr[cap] = max(inc, exc); 
			if (index == n-1)
				break;
		}
	}

	return curr[maxWeight];
}


int knapsack(vector<int> &weight, vector<int> &value, int n, int maxWeight) 
{
	return solveSO(weight, value, n, maxWeight);
}