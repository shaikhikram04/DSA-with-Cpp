//! T.C -> O(n)
//! S.C -> O(n)

//* Tabulation

#include <bits/stdc++.h> 
using namespace std;

class Solution {
    int solveTab(int n, vector<int> days, vector<int> cost) {
        vector<int> dp(n+1, 0);

        dp[n] = 0;

        for (int i = n-1; i >= 0; i--) {
            //* 1-day pass
            int option1 = cost[0] + dp[i+1];
            
            int index;
            //* 7-day pass
            for (index = i; index < n && days[index] < days[i]+7; index++); //* it take O(1) T.C
            int option2 = cost[1] + dp[index];

            //* 30-day pass
            for (index = i; index < n && days[index] < days[i]+30; index++); //* it take O(1) T.C
            int option3 = cost[2] + dp[index];

            dp[i] = min(option1, min(option2, option3));
        }

        return dp[0];
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        return solveTab(n, days, costs);
    }
};