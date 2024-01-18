//! T.C -> O(n)
//! S.C -> O(1)

//* Space Optimization

#include <bits/stdc++.h> 
using namespace std;


class Solution {

    int solveSO(vector<int>& prices) {
        vector<vector<int>> curr(2, vector<int> (3, 0));
        vector<vector<int>> next(2, vector<int> (3, 0));

        for (int index = prices.size()-1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int remSell = 1; remSell <= 2; remSell++) {
                    int profit = 0;
                    if (buy) {
                        int buyStock = -prices[index] + next[0][remSell];
                        int skipToBuy = next[1][remSell];
                        profit = max(buyStock, skipToBuy);
                    }
                    else {
                        int sellStock = prices[index] + next[1][remSell-1];
                        int skipToSell = next[0][remSell];
                        profit = max(sellStock, skipToSell);
                    }

                    curr[buy][remSell] = profit;
                }
            }
            next = curr;
        }

        return curr[1][2];
    }

public:
    int maxProfit(vector<int>& prices) {
        return solveSO(prices);
    }
};