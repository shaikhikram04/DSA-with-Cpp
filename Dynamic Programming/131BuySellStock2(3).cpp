//! T.C -> O(n)
//! S.C -> O(1)

//* Space Optimization

#include <bits/stdc++.h> 
using namespace std;

class Solution {

    int solveSO(vector<int>& prices) {
        int n = prices.size();
        vector<int> curr(3, 0);
        vector<int> next(3, 0);

        for (int index = n-1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy) {
                    profit = max(-prices[index]+next[0], next[1]);
                }
                else {
                    profit = max(prices[index]+next[1], next[0]);
                }

                curr[buy] = profit;
            }
            next = curr;
        }
        return curr[1];
    }
public:
    int maxProfit(vector<int>& prices) {
        return solveSO(prices);
    }
};