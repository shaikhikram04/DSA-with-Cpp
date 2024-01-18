//! T.C -> O(n)
//! S.C -> O(n)

//* Tabulation

#include <bits/stdc++.h> 
using namespace std;

class Solution {

    int solveTab(vector<int>& prices) {
        //* create dp array  also manage base case
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>> (2, vector<int> (3, 0)));

        //* Solve for remaining case
        for (int index = prices.size()-1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int remSell = 1; remSell <= 2; remSell++) {
                    int profit = 0;
                    if (buy) {
                        int buyStock = -prices[index] + dp[index+1][0][remSell];
                        int skipToBuy = dp[index+1][1][remSell];
                        profit = max(buyStock, skipToBuy);
                    }
                    else {
                        int sellStock = prices[index] + dp[index+1][1][remSell-1];
                        int skipToSell = dp[index+1][0][remSell];
                        profit = max(sellStock, skipToSell);
                    }

                    dp[index][buy][remSell] = profit;
                }
            }
        }

        return dp[0][1][2];
    }

public:
    int maxProfit(vector<int>& prices) {
        return solveTab(prices);
    }
};