#include <bits/stdc++.h> 
using namespace std;

void heapify(vector<int> &arr, int index, int n) {
    int largest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;
    
    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;
        
    if (largest != index) {
        swap(arr[largest], arr[index]);
        
        heapify(arr, largest, n);
    }
}

void heapSort(vector<int> &arr, int size) {
    while (size > 1) {
        swap(arr[0], arr[size-1]);
        size--;
        heapify(arr, 0, size);
    }
}

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> ans;
    for (int i = 0; i < kArrays.size(); i++) {
        for (int j = 0; j < kArrays[i].size(); j++) {
            ans.push_back(kArrays[i][j]);
        }
    }
    
    int n = ans.size();
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(ans, i, n);
    }

    heapSort(ans, n);
    
    return ans;
}
