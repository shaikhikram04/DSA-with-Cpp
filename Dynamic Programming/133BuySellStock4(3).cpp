//! T.C -> O(n*k)
//! S.C -> O(k)

//* Space Optimization

#include <bits/stdc++.h> 
using namespace std;

class Solution {

    int solveSO(int k, vector<int>& prices) {
        int n = prices.size();

        vector<int> curr(2*k+1, 0);
        vector<int> next(2*k+1, 0);

        for (int index = n-1; index >= 0; index--) {
            for (int limit = 2*k-1; limit >= 0; limit--) {
                int profit = 0;
                // odd -> sell
                if (limit & 1) {
                    int sellStock = prices[index] + next[limit+1];
                    int skipToSell = next[limit];
                    profit = max(sellStock, skipToSell);
                }
                // even -> buy
                else {
                    int buyStock = -prices[index] + next[limit+1];
                    int skipToBuy = next[limit];
                    profit = max(buyStock, skipToBuy);
                }

                curr[limit] = profit;
            }
            next = curr;
        }
        return curr[0];
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        return solveSO(k, prices);
    }
};