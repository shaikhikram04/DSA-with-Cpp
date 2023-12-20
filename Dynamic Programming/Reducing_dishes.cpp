//? https://leetcode.com/problems/reducing-dishes/description/

//! T.C -> O(n^2)
//! S.C -> O(n^2)

//* Recursion + Memoization

#include <bits/stdc++.h> 
using namespace std;


class Solution {
    int solveMem(vector<int>& satisfaction, int index, int time, vector<vector<int>> &dp) {
        if (index >= satisfaction.size())
            return 0;

        if (dp[index][time] != -1)
            return dp[index][time];

        //* include
        //? Here we start time from 0 thats why we multiply current satisfaction with (time+1)
        //? And solve for next index with incrementing time
        int inc = (time+1)*satisfaction[index] + solveMem(satisfaction, index+1, time+1, dp);

        //* exclude
        //? Here we exclude so no need to add current TLC
        int exc = solveMem(satisfaction, index+1, time, dp);

        
        return dp[index][time] = max(inc, exc);
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());

        int n = satisfaction.size();

        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solveMem(satisfaction, 0, 0, dp);
    }
};