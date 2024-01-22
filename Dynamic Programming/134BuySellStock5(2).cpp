//! T.C -> O(n)
//! S.C -> O(n)

//* Tabulation

#include <bits/stdc++.h> 
using namespace std;

class Solution {

    int solveTab(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (3, 0));

        for (int index = n-1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy) {
                    int buyStock = -prices[index] + dp[index+1][0];
                    int skipToBuy = dp[index+1][1];
                    profit = max(buyStock, skipToBuy);
                }
                else {
                    int sellStock = prices[index] - fee + dp[index+1][1];
                    int skipToSell = dp[index+1][0];
                    profit = max(sellStock, skipToSell);
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        return solveTab(prices, fee);
    }
};