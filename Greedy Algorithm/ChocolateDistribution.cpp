//? https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

//! T.C -> O(n*log(n))
//! S.C -> O(1)

//* sort, greedy

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m) {
        //* sort array in ascending order
        sort(a.begin(), a.end());
    
        //* take m chocolate packet from sorted array from i to j
        int i = 0;
        int j = m-1;
        
        //* it store minimum diff between each max & min chocolate packet
        //* initially it is INT_MAX
        long long minDiff = INT_MAX;

        //* Iterate each sub-array of m size
        while (j < n) {
            //* update minimum difference
            minDiff = min(minDiff, (a[j++] - a[i++]));
        }
        
        //* return minimum difference
        return minDiff;
    }   
};