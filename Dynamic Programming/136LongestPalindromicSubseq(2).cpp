//! T.C -> O(n^2)
//! S.C -> O(n^2)

//* Tabulation

#include <bits/stdc++.h> 
using namespace std;

class Solution {

    int solveTab(string s) {
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                int len = (i != j) ? 2 : 1;

                if (s[i] == s[j]) {
                    dp[i][j+1] = len + dp[i+1][j];
                }
                else {
                    dp[i][j+1] = max(dp[i+1][j+1], dp[i][j]);
                }
            }
        }

        return dp[0][n];
    }

public:
    int longestPalindromeSubseq(string s) {
        return solveTab(s);
    }
};