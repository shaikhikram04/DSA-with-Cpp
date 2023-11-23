//? //? https://leetcode.com/problems/coin-change/description/

//! T.C -> O(amount * n)
//! S.C -> O(amount)

#include <bits/stdc++.h> 
using namespace std;

int solveTab(vector<int> &coins, int amount) {

    //* create a dp table
    vector<int> dp(amount+1, INT_MAX);

    //* assign dp[0] = 0 
    dp[0] = 0;

    //* solve for every amount figure from 1 to x
    for (int i = 1; i <= amount; i++) {
        //* finding minimum value by including all element one by one
        for (int j = 0; j < coins.size(); j++) {
            if (i - coins[j] >= 0 && dp[i-coins[j]] != INT_MAX) {
                dp[i] = min( dp[i], 1 + dp[i-coins[j]] ); 
            }
        }
    }
    return dp[amount];
}


int minimumElements(vector<int> &coins, int amount)
{
    int ans = solveTab(coins, amount);

    if (ans == INT_MAX)
        return -1;
    else    
        return ans;
}