// https://www.codingninjas.com/studio/problems/elements-occur-more-than-n-k-times_1113146?topList=love-babbar-dsa-sheet-problems

#include <bits/stdc++.h> 
using namespace std;

vector<int> countTheNumber(vector<int> &arr, int n, int k) {
	vector<int> mostOccured;

	unordered_map<int, int> cnt;
	int N = n/k;

	for (int i : arr) {
		cnt[i]++;
	}

	for (auto i : cnt) {
		if (i.second >= n/k) {
			mostOccured.push_back(i.first);
		}
	}

	return mostOccured;
}