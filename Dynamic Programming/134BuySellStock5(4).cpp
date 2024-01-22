//! T.C -> O(n)
//! S.C -> O(1)

//* Optimal Approach

#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        //* It store price that we have after buying a stock
        //* if it is in -ve that means we are in loss
        //* Obviously we try to store maximum value(to be in good profit)
        int buy = INT_MIN;

        //* It store profit
        //* initially it is 0
        int sell = 0;

        //* iterate prices array
        for (int price : prices) {
            //* store max of previous buy price and 
            //* price that left after buying curr stock
            buy = max(buy, sell - price);

            //* Store max previous profit prices and
            //* price that left after sell curr stock with paying fee
            sell = max(sell, buy + price - fee);
        }

        return sell;
    }
};