//! T.C -> O(n)
//! S.C -> O(1)

//* Optimal Approach

#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //* It store profit
        int profit = 0;
        //* It store price of stock that we bought
        //* initially we buy stock of day-1
        int buy = prices[0];

        //* Find right day to sell stock and buy another one
        for (int i = 1; i < prices.size(); i++) {
            //* If curr stock price is minimum that previous then we sell the stock that we hold in curr-1 day
            //* because from curr stock price getting down so we sell it on curr-1 
            if (prices[i] < prices[i-1]) {
                //* sell stock and accumulate its value in profit variable
                profit += prices[i-1] - buy;
                //* Buy stock of curr day
                buy = prices[i];
            }
        }
        //* sell stock on last day
        profit += prices[n-1] - buy;

        //* return profit
        return profit;
    }
};