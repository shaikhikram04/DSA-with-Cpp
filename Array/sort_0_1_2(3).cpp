//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int mid = 0;
        int high = n - 1;
        int low = 0;
        while (mid <= high) {
            if (a[mid] == 0){
                swap(a[mid], a[low]);
                low++;
                mid++;
            }
            else if (a[mid] == 1) {
                mid++;
            }
            else if (a[mid] == 2) {
                swap(a[mid], a[high]);
                high--;
            }
        }
    }
};
