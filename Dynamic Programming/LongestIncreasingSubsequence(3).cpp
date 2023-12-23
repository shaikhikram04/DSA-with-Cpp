//! T.C -> O(n*n)
//! S.C -> O(n)

//* Space Optimization

#include <bits/stdc++.h> 
using namespace std;


class Solution
{   
    int solveSO(int n, int a[]) {
        vector<int> currRow(n+1, 0);
        
        for (int curr = n-1; curr >= 0; curr--) {
            for (int prev = -1; prev < curr; prev++) {
                //* include
                int inc = 0;
                if (prev == -1 || a[curr] > a[prev])
                    inc = 1 + currRow[curr+1];
                
                //* exclude
                int exc = currRow[prev+1];
                
                
                currRow[prev+1] = max(inc, exc);
            }
        }
        
        return currRow[0];
    }
    
    public:
    int longestSubsequence(int n, int a[])
    {
        return solveSO(n, a);
    }
};