// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

#include <queue>
using namespace std;

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int> maxHeap;
        for (int i = 0; i < k; i++) {
            maxHeap.push(arr[i]);
        }
        
        for (int i = k; i <= r; i++) {
            if (arr[i] < maxHeap.top()) {
                maxHeap.pop();
                maxHeap.push(arr[i]);
            }
        }
        
        return maxHeap.top();
    }
};