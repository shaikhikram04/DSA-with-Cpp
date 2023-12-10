//? https://leetcode.com/problems/minimum-cost-for-tickets/description/

//! T.C -> O(n)
//! S.C -> O(n)

//* Recursion + Memoization

#include <bits/stdc++.h> 
using namespace std;

class Solution {
    int solveMem(int n, vector<int> &days, vector<int> &cost, int index, vector<int> &dp) {
        //* base case
        if (index >= n)
            return 0;

        if (dp[index] != -1)
            return dp[index];

        //* 1-day pass
        int day1 = cost[0] + solveMem(n, days, cost, index+1, dp);

        int i;
        //* 7-day pass
        for (i = index; i < n && days[i] < days[index]+7; i++); //* it take O(1) T.C
        int day7 = cost[1] + solveMem(n, days, cost, i, dp);

        //* 30-day pass
        for (i = index; i < n && days[i] < days[index]+30; i++); //* it take O(1) T.C
        int day30 = cost[2] + solveMem(n, days, cost, i, dp);

        dp[index] = min(day1, min(day7, day30));
        return dp[index];
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, -1);
        return solveMem(n, days, costs, 0, dp);
    }
};