//? k -> size of array

//! T.C -> O(k*k)
//! S.C -> O(k*k)

//* Tabulation

#include <bits/stdc++.h> 
using namespace std;

class Solution {

    int solveTab(int startIndex, int endIndex, vector<int>& slices) {
        int k = slices.size();
        int n = k/3;
        vector<vector<int>> dp(k+2, vector<int> (n+1, 0));

        for (int i = endIndex; i >= startIndex; i--) {
            for (int j = 1; j <= n; j++) {
                int take = slices[i] + dp[i+2][j-1];
                int notTake = dp[i+1][j];

                dp[i][j] = max(take, notTake);
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