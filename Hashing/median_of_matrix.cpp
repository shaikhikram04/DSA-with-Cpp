// https://www.codingninjas.com/studio/problems/median-in-matrix_981178?topList=love-babbar-dsa-sheet-problems

#include <bits/stdc++.h> 
using namespace std;

int findMedian(vector<vector<int> > &arr, int n, int m){
	
	map<int, int> cnt;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cnt[arr[i][j]]++;
		}
	}


	
	int count = 0;
	int totalSize = n*m;
	map<int, int> :: iterator it;
	
	for (it = cnt.begin(); it != cnt.end(); it++) {
		count += it->second;
		
		if (count >= (totalSize + 1)/2) {
			break;
		}
	}

	return it->first;
	
}
