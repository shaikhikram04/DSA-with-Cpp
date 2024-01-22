//! T.C -> O(n)
//! S.C -> O(1)

//* Space Optimization

#include <bits/stdc++.h> 
using namespace std;

class Solution {

    int solveSO(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> curr(3, 0);
        vector<int> next(3, 0);

        for (int index = n-1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy) {
                    int buyStock = -prices[index] + next[0];
                    int skipToBuy = next[1];
                    profit = max(buyStock, skipToBuy);
                }
                else {
                    int sellStock = prices[index] - fee + next[1];
                    int skipToSell = next[0];
                    profit = max(sellStock, skipToSell);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return curr[1];
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        return solveSO(prices, fee);
    }
};