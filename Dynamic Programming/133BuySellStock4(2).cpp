//! T.C -> O(n*k)
//! S.C -> O(n*k)

//* Tabulation

#include <bits/stdc++.h> 
using namespace std;

class Solution {

    int solveTab(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2*k+1, 0));

        for (int index = n-1; index >= 0; index--) {
            for (int limit = 2*k-1; limit >= 0; limit--) {
                int profit = 0;
                //* odd -> sell
                if (limit & 1) {
                    int sellStock = prices[index] + dp[index+1][limit+1];
                    int skipToSell = dp[index+1][limit];
                    profit = max(sellStock, skipToSell);
                }
                //* even -> buy
                else {
                    int buyStock = -prices[index] + dp[index+1][limit+1];
                    int skipToBuy = dp[index+1][limit];
                    profit = max(buyStock, skipToBuy);
                }

                dp[index][limit] = profit;
            }
        }
        return dp[0][0];
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        return solveTab(k, prices);
    }
};