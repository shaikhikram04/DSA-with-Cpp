//? https://leetcode.com/problems/russian-doll-envelopes/description/

//! T.C -> O(n*log n)
//! S.C -> O(n)

//* DP + Binary Search

#include <bits/stdc++.h> 
using namespace std;

class Solution {

    static bool compare(vector<int>& a, vector<int>& b) {
        //* if first value is same the arrange vector in decreasing order of 2nd value
        if (a[0] == b[0])
            return a[1] > b[1];

        return a[0] < b[0];
    }

public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), compare);

        int n = envelopes.size();

        //* Now we apply DP+Binary Search algo in height(2nd val which is unsorted) only

        //* array that store strictly increasing sequence
        vector<int> ans;
        //* store 1st element of array
        ans.push_back(envelopes[0][1]);

        //* Traverse remaining array
        for (int i = 1; i < n; i++) {
            //* If ith val of array is greater than last value of seq array then push curr val in seq array
            if (envelopes[i][1] > ans.back()) {
                ans.push_back(envelopes[i][1]);
            }
            else {
                //* lower_bound return the index of left most occurrence of a[i] if a[i] is present otherwise
                //* it return index of just greater number of a[i]
                //* It take O(log n) time complexity
                int index = lower_bound(ans.begin(), ans.end(), envelopes[i][1]) - ans.begin();
                //* Update that index return by lover_bound
                ans[index] = envelopes[i][1];
            }
        }

        //* return size of sequence array
        return ans.size();
    }
};