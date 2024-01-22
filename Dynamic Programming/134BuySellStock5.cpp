//? https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

//! T.C -> O(n)
//! S.C -> O(n)

//* Recursion + Memoization

#include <bits/stdc++.h> 
using namespace std;

class Solution {
    //* buy says that we can buy curr stock or not
    //! buy == 1 -> can buy
    //! buy == 0 -> cant buy (i.e. can sell)
    int solveMem(vector<int>& prices, int fee, int index, bool buy, vector<vector<int>>& dp) {
        //* if array is empty then return 0
        if (index >= prices.size())
            return 0;

        //* if ans is already present then return it
        if (dp[index][buy] != -1)
            return dp[index][buy];

        //* It store profit
        int profit = 0;

        //? buy == 1
        //* buy curr stock or skip
        if (buy) {
            int buyStock = -prices[index] + solveMem(prices, fee, index+1, 0, dp);
            int skipToBuy = solveMem(prices, fee, index+1 , 1, dp);
            profit = max(buyStock, skipToBuy);
        }
        //* sell curr stock or skip
        else {
            //* when we sell a stock(i.e. transaction completed) then we have to pay fee so subtract fee from profit
            int sellStock = prices[index] - fee + solveMem(prices, fee, index+1, 1, dp);
            int skipToSell = solveMem(prices, fee, index+1, 0, dp);
            profit = max(sellStock, skipToSell);
        }

        //* store in dp and return profit
        return dp[index][buy] = profit;
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int> (2, -1));
        return solveMem(prices, fee, 0, 1, dp);
    }
};