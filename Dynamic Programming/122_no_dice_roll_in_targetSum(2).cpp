
//! T.C -> O(n*target)
//! S.C -> O(n*target)

//* Tabulation

#include <bits/stdc++.h> 
using namespace std;

#define mod 1000000007

class Solution {

    int solveTab(int n, int k, int target) {
        //* create 2D dp array with all 0's
        vector<vector<int>> dp(n+1,vector<int> (target+1, 0));

        //* if there is no dice remaining And we complete target that means it is a possible way so return 1
        dp[0][0] = 1;

        //* solve for remaining
        for (int dice = 1; dice <= n; dice++) {
            for (int tar = 1; tar <= target; tar++) {
                //* assign ans = 0 to store no. of possible ways if no. of dice is n and target is target
                int ans = 0;

                //* check for all possible faces of dice(from 1 to k also it should be less than or equal to target) which can make a target
                //* accumulate its result in ans
                for (int i = 1; i <= k && i <= tar; i++) {
                    ans = (ans + dp[dice-1][tar-i]) % mod;
                }
                dp[dice][tar] = ans;
            }
        }

        //* return ans
        return dp[n][target];
    }

public:
    int numRollsToTarget(int n, int k, int target) {

        return solveTab(n, k, target);
    }
};