#include <vector>
using namespace std;

class Solution{
    void heapify(vector<int> &arr, int n, int i) {
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;
        
        if (l < n && arr[l] > arr[largest])
            largest = l;
            
        if (r < n && arr[r] > arr[largest])
            largest = r;
            
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        for (int i = 0; i < m; i++) {
            a.push_back(b[i]);
        }
        
        for (int i = (m + n)/2 - 1; i >= 0; i--) {
            heapify (a, m+n, i);
        }
        
        return a;
    }
};