//? https://leetcode.com/problems/coin-change/description/

//! T.C -> O(amount * n)
//! S.C -> O(amount)

#include <bits/stdc++.h> 
using namespace std;

int solveRecMem(vector<int> &coins, int amount, vector<int> &dp) {
    //* base case
    if (amount == 0)
        return 0;

    if (amount < 0)
        return INT_MAX;

    if (dp[amount] != -1)
        return dp[amount];

    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++) {
        int ans = solveRecMem(coins, amount-coins[i], dp);

        if (ans != INT_MAX)
            mini = min(1+ans, mini);
    }
    dp[amount] = mini;

    return mini;
}
int minimumElements(vector<int> &coins, int amount)
{   
    vector<int> dp(amount+1, -1);
    int ans = solveRecMem(coins, amount, dp);
    if (ans == INT_MAX)
        return -1;

    return ans;
}