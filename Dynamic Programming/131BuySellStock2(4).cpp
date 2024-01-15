//! T.C -> O(n)
//! S.C -> O(1)

//* 

#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buy = prices[0];
        int sell = buy;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < sell) {
                profit += sell - buy;
                buy = sell = prices[i];
            }
            else {
                sell = prices[i];
            }
        }
        profit += sell - buy;
        
        return profit;
    }
};