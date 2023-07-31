// https://www.codingninjas.com/studio/problems/median-in-a-stream_975268?leftPanelTab=0

// T.C -> O(n^2)
// S.C -> O(1)

#include <bits/stdc++.h> 
using namespace std; 

int median(vector<int> &arr, int n) {

	int i = n-1;
	int temp = arr[i];
	int j;
	for (j = i-1; j >= 0; j--) {
		if (arr[j] > temp) {
			arr[j+1] = arr[j];
		} else {
			break;
		}
	}

	arr[j+1] = temp;

	// size of array is odd
	if (n % 2) {
		return arr[n/2];
	} 
	// size is even
	else {
		int first = arr[n/2 - 1];
		int second = arr[n/2];
		return (first + second)/2;
	}
}

vector<int> findMedian(vector<int> &arr, int n){
	vector<int> ans;
	for (int i = 0; i < n; i ++) {
		ans.push_back(median(arr, i+1));
	}

	return ans;
}
