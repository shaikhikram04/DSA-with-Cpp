//! T.C -> O(n^3)
//! S.C -> O(n^3)

//* Tabulation

#include <bits/stdc++.h> 
using namespace std;

class Solution {
    int solveTab(int n) {
        //* create dp array
        vector<vector<int>> dp(n+2, vector<int> (n+2, 0));

        //* Solve for each possible range
        for (int start = n; start >= 1; start--) {
            for (int end = start+1; end <= n; end++) {
                //* finding manimal and of each range
                int minAns = INT_MAX;
                for (int i = start; i <= end; i++) {
                    int ans = max(dp[i+1][end], dp[start][i-1]) + i;
                    minAns = min(minAns, ans);
                }
                dp[start][end] = minAns;
            }
        }

        //* return ans when range is 1->n
        return dp[1][n];
    }

public:
    int getMoneyAmount(int n) {
        return solveTab(n);
    }
};