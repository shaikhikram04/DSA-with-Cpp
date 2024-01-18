//! T.C -> O(n)
//! S.C -> O(n)

//* Tabulation

#include <bits/stdc++.h> 
using namespace std;

class Solution {

    int solveTab(vector<int>& prices) {
        int n = prices.size();
        //* Create dp array of n+1 * 3 with all 0's(to handle base case)
        vector<vector<int>> dp(n+1, vector<int> (3, 0));

        //* solve for remaining cases
        for (int index = n-1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy) {
                    profit = max(-prices[index]+dp[index+1][0], dp[index+1][1]);
                }
                else {
                    profit = max(prices[index]+dp[index+1][1], dp[index+1][0]);
                }

                dp[index][buy] = profit;
            }
        }
        //* return ans when index->0 and we can buy initially
        return dp[0][1];
    }
public:
    int maxProfit(vector<int>& prices) {
        return solveTab(prices);
    }
};