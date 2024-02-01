//! T.C -> O(n*m)
//! S.C -> O(n*m)

//* Tabulation

#include <bits/stdc++.h> 
using namespace std;

class Solution {

    bool solveTab(string& s, string& p) {
        int n = s.length();
        int m = p.length();
        
        //* creating dp array of (n+1)*(m+1) with all false
        vector<vector<bool>> dp(n+1,vector<bool> (m+1, false));

        //? base case : managing true case because we initialize all dp with false
        dp[n][m] = true;
        bool onlyAsterics = true;
        for (int j = m-1; j >= 0; j--) {
            //* If There is any char which is not * in subarray then update onlyAsterics to false
            if (p[j] != '*')    onlyAsterics = false;
            dp[n][j] = onlyAsterics;
        }

        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                //* solve for all 3 cases
                if (s[i] == p[j] || p[j] == '?') 
                    dp[i][j] = dp[i+1][j+1];
                
                else if (p[j] == '*') 
                    dp[i][j] = (dp[i][j+1] || dp[i+1][j]);
                
                else
                    dp[i][j] = false;
            }
        }

        //* return ans when we start from 0th index of both string
        return dp[0][0];
    }

public:
    bool isMatch(string& s, string& p) {
        return solveTab(s, p);
    }
};