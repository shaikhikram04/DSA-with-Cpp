
// T.C -> O(n * log(n))
// S.C -> O(n)

#include <bits/stdc++.h>
using namespace std;

int signum(priority_queue<int> maxHeap, priority_queue<int, vector<int>, greater<int> > minHeap) {
	if (maxHeap.size() == minHeap.size())
		return 0;
		
	else if (maxHeap.size() > minHeap.size())
		return 1;
		
	else
		return -1;
}

int average(int a, int b) {
	return (a + b) / 2;
}

vector<int> findMedian(vector<int> &arr, int n){
	
	vector<int> ans;
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int> > minHeap;
	int median = -1;

	for (int i = 0; i < n; i++) {
		int element = arr[i];
		
		switch (signum(maxHeap, minHeap)) {
			case 0:
				if (element > median) {
					minHeap.push(element);
					median = minHeap.top();
				} else {
					maxHeap.push(element);
					median = maxHeap.top();
				}
				break;
			case 1:
				if (element > median) {
					minHeap.push(element);
				} else {
					minHeap.push(maxHeap.top());
					maxHeap.pop();
					
					maxHeap.push(element);
				}
				median = average(maxHeap.top(), minHeap.top());
				break;
			case -1:
				if (element > median) {
					maxHeap.push(minHeap.top());
					minHeap.pop();
					
					minHeap.push(element);
				} else {
					maxHeap.push(element);
				}
				median = average(maxHeap.top(), minHeap.top());
				break;
		}
		ans.push_back(median);
	}

	return ans;
}
