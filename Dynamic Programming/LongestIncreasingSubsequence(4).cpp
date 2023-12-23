//! T.C -> O(n*log n)
//! S.C -> O(n)

//* DP + Binary Search

#include <bits/stdc++.h> 
using namespace std;


class Solution
{
    public:
    int longestSubsequence(int n, int a[])
    {
        //* array that store strictly increasing sequence
        vector<int> seq;
        //* store 1st element of array
        seq.push_back(a[0]);
        
        //* Traverse remaining array
        for (int i = 1; i < n; i++) {
            //* If ith val of array is greater than last value of seq array then push curr val in seq array
            if (a[i] > seq.back())
                seq.push_back(a[i]);
                
            //* Otherwise
            else {
                //* lower_bound return the index of left most occurrence of a[i] if a[i] is present otherwise
                //* it return index of just greater number of a[i]
                //* It take O(log n) time complexity
                int index = lower_bound(seq.begin(), seq.end(), a[i]) - seq.begin();
                //* Update that index return by lover_bound
                seq[index] = a[i];
            }
        }
        
        //* return size of sequence array
        return seq.size();
    }
};