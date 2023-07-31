// https://www.codingninjas.com/studio/problems/k-th-largest-sum-contiguous-subarray_920398?leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

int getKthLargest(vector<int> &arr, int k)
{
	vector<int> sumStore;
	int n = arr.size();

	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += arr[j];
			sumStore.push_back(sum);
		}
	}

	sort(sumStore.begin(), sumStore.end());

	return sumStore[sumStore.size() - k ];
}