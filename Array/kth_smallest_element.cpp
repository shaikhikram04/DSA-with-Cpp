//? problem link : https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

//! T.C -> O(n * log n)
//! S.C -> O(1)

#include <set>
#include <algorithm>
using namespace std;

class Solution{
    public:
    //* arr : given array
    //* l : starting index of the array i.e 0
    //* r : ending index of the array i.e size-1
    //* k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        sort(arr, arr + r + 1);
        
        return arr[k-1];
    }
};