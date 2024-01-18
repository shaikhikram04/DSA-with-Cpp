//? https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

//! T.C -> O(n^2)
//! S.C -> O(n)

//* Recursion + Memoization

#include <bits/stdc++.h> 
using namespace std;


class Solution {
    //* buy => inndicate that we can buy curr stock or not... 1->can buy  &  0->cant buy
    //* remSell => indicate that no. of remaining transaction i.e. remaining stock to sell(that we already buy)
    //* 1 transection is compleated when we buy a stock and sell it
    int solveMem(vector<int>& prices, int index, int buy, int remSell, vector<vector<vector<int>>>& dp) {
        //* if array is empty or there is no transaction remaining then return 0.
        if (index >= prices.size() || remSell == 0)
            return 0;

        //* If ans already stored then return it        
        if (dp[index][buy][remSell] != -1)
            return dp[index][buy][remSell];

        //* It store maximum profit
        int profit = 0;

        //* If we can buy stock(i.e. we are currently not hold any stock)'
        //* here we can buy stock or skip to buy
        if (buy) {
            //* find ans when we buy stock, if we buy then we have to pay money (i.e. we losses some money) so, we will add -prices[index] in remaining ans
            //* buy -> 0 because after buying curr stock we cant buy any stock before sell it.
            //* remSell will same Because it will decrement when complete transaction completed
            int buyStock = -prices[index] + solveMem(prices, index+1, 0, remSell, dp);

            //* also find ans when we skip to buy curr stock
            int skipToBuy = solveMem(prices, index+1, 1, remSell, dp);

            //* Then Store maximum of both in profit variable
            profit = max(buyStock, skipToBuy);
        }
        //* If we can't buy stock because we already hold a stock
        //* So here we can sell stock or skip to sell
        else {
            //* Find ans then we sell stock, if we sell stock then we get price so we add price of that stock & recursive call for remaining ans
            //* buy -> 1 because here we sell a stock that we hold so we can buy another stock
            //* remSell decrement Because after sell our transaction is completed so remSell get decrement by 1
            int sellStock = prices[index] + solveMem(prices, index+1, 1, remSell-1, dp);

            //* also find ans when we skip to sell curr stock
            int skipToSell = solveMem(prices, index+1, 0, remSell, dp);

            //* Then Store maximum of both in profit varible
            profit = max(sellStock, skipToSell);
        }

        //* Store in dp array and return profit
        return dp[index][buy][remSell] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        //* We can complete almost 2 transaction

        //* here we need 3d dp
        //* row -> index  ,  col -> buy or not  ,  height -> no. of remaining stock to sell
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>> (2, vector<int> (3, -1)));
        return solveMem(prices, 0, 1, 2, dp);
    }
};