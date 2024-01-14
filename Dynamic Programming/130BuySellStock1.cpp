//? https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

//! T.C -> O(n)
//! S.C -> O(1)

#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //* Store the maximum profit initialize with 0
        int profit = 0;
        //* Store Stock value that we buy
        int buyVal = prices[0];

        //* Iterate from 1 -> n-1 to find right time to sell if we bought stock whwn it value is "buyVal"
        for (int i = 1; i < prices.size(); i++) {
            //* if curr stock value is greater than by value then update profit as we sell stock
            if (prices[i] > buyVal) {
                profit = max(profit, prices[i]-buyVal);
            }
            //* Otherwise update buyVal because we get smaller val then buyVal
            else {
                buyVal = prices[i];
            }
        }

        //* return profit
        return profit;
    }
};