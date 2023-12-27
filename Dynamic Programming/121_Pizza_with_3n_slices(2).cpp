//? k -> size of array

//! T.C -> O(k*k)
//! S.C -> O(k*k)

//* Tabulation

#include <bits/stdc++.h> 
using namespace std;

class Solution {

    int solveTab(int startIndex, int endIndex, vector<int>& slices) {
        //* k -> total no. of slices
        int k = slices.size();
        //* n -> no. of slices each person can eat
        int n = k/3;
        //* Initialize all with 0 because base case return 0
        vector<vector<int>> dp(k+2, vector<int> (n+1, 0));

        for (int index = endIndex; index >= startIndex; index--) {
            for (int n1 = 1; n1 <= n; n1++) {
                int take = slices[index] + dp[index+2][n1-1];
                int notTake = dp[index+1][n1];

                dp[index][n1] = max(take, notTake);
            }
        }

        return dp[startIndex][n];
    }

public:
    int maxSizeSlices(vector<int>& slices) {

        int k = slices.size();

        int case1 = solveTab(0, k-2, slices);

        int case2 = solveTab(1, k-1, slices);

        return max(case1, case2);
    }
};