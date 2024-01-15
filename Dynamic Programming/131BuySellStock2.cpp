//? https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

//! T.C -> O(n^2)
//! S.C -> O(n)

//* Recursion + Memoization

#include <bits/stdc++.h> 
using namespace std;

class Solution {
    int solveMem(vector<int>& prices, int index, int buy, vector<vector<int>>& dp) {
        //* If there is no element in prices array then return 0
        if (index >= prices.size())
            return 0;

        //* If ans already stored then return it
        if (dp[index][buy] != -1)
            return dp[index][buy];

        //* It store maximum profit
        int profit = 0;

        //* If we can buy stock(i.e. we are currently not hold any stock)'
        //* So here we buy stock or skip to buy
        if (buy) {
            //* find ans when we buy stock, if we buy then we have to pay money (i.e. we losses some money) so, we will add -prices[index] in remaining ans
            //* also find ans when we skip to buy curr stock
            //* Then Store maximum of both in profit variable
            profit = max(-prices[index]+solveMem(prices,index+1,0,dp), solveMem(prices,index+1,1,dp));
        }
        //* If we can't buy stock because we already hold a stock
        //* So here we sell stock or skip to sell
        else {
            //* Find ans then we sell stock, if we sell stock then we get price so we add price of that stock & recursive call for remaining ans
            //* also find ans when we skip to sell curr stock
            //* Then Store maximum of both in profit varible
            profit = max(prices[index]+solveMem(prices,index+1,1,dp), solveMem(prices,index+1,0,dp));
        }

        //* Store in dp array and return profit
        return dp[index][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int> (2, -1));

        return solveMem(prices, 0, 1, dp);
    }
};