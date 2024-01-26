//! T.C -> O(n*m)
//! S.C -> O(n*m)

//* Tabulation

#include <bits/stdc++.h> 
using namespace std;

class Solution {

    int solveTab(string& a, string& b) {
        int n = a.length();
        int m = b.length();

        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        //* analyse and store base case
        for (int i = 0; i < n; i++) {
            dp[i][m] = n - i;
        }
        for (int j = 0; j < m; j++) {
            dp[n][j] = m - j;
        }

        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) { 
                //! if char match
                if (a[i] == b[j]) {
                    dp[i][j] = dp[i+1][j+1];
                }
                else {
                    //? insert
                    int insertAns = 1 + dp[i][j+1];

                    //? delete
                    int delAns = 1 + dp[i+1][j];

                    //? replace
                    int replaceAns = 1 + dp[i+1][j+1];

                    dp[i][j] = min(insertAns, min(delAns, replaceAns));
                }
            }
        }
        return dp[0][0];
    }

public:
    int minDistance(string word1, string word2) {
        return solveTab(word1, word2);
    }
};