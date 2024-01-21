//? https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

//! T.C -> O(n*k)
//! S.C -> O(n*k)

//* Recursion + Memoization

#include <bits/stdc++.h> 
using namespace std;

class Solution {
    //* k -> maximum number of transaction 
    //* limit -> no. of operation(buy or sell) that we perforned
    int solveMem(vector<int>& prices, int k, int index, int limit, vector<vector<int>>& dp) {
        //! if there is no element in array OR all operations were performed then return 0
        if (index >= prices.size() || limit >= 2*k) {
            return 0;
        }

        //* if already had ans then return it
        if (dp[index][limit] != -1)
            return dp[index][limit];

        //* To store profit
        int profit = 0;

        //? odd -> sell
        //* if limit is odd -> its time to sell or skip
        if (limit & 1) {
            int sellStock = prices[index] + solveMem(prices, k, index+1, limit+1, dp);
            int skipToSell = solveMem(prices, k, index+1, limit, dp);
            profit = max(sellStock, skipToSell);
        }

        //? even -> buy
        //* if limit is even -> its time to buy or skip
        else {
            int buyStock = -prices[index] + solveMem(prices, k, index+1, limit+1, dp);
            int skipToBuy = solveMem(prices, k, index+1, limit, dp);
            profit = max(buyStock, skipToBuy);
        }

        //* Store in dp and return the profit
        return dp[index][limit] = profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int> (2*k, -1));
        return solveMem(prices, k, 0, 0, dp);
    }
};