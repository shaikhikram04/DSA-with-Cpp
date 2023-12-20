//! T.C -> O(n^2)
//! S.C -> O(n^2)

//* Tabulation

#include <bits/stdc++.h> 
using namespace std;


class Solution {
    int solveTab(vector<int>& sat) {
        sort(sat.begin(), sat.end());

        int n = sat.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

        for (int i = n-1; i >= 0; i--) {
            for (int time = n-1; time >= 0; time--) {
                // include
                int inc = (time+1)*sat[i] + dp[i+1][time+1];
                // exclude
                int exc = dp[i+1][time];

                dp[i][time] = max(inc, exc);
            }
        }

        return dp[0][0];
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        return solveTab(satisfaction);
    }
};