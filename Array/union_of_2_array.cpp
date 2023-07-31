// https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1

#include <unordered_map>
using namespace std;

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        unordered_map<int,int> occurrance;
        for (int i = 0; i < n; i++) {
            occurrance[a[i]]++;
        }
        for (int j = 0; j < m; j++) {
            occurrance[b[j]]++;
        }
        return occurrance.size();
    }
};