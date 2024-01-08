//? https://leetcode.com/problems/unique-binary-search-trees/description/

//! T.C -> O(n^2)
//! S.C -> O(n)

//* Recursion + Memoization

#include <bits/stdc++.h> 
using namespace std;

class Solution {
    int solveRec(int n, vector<int>& dp) {
        //* if n == 0 OR n == 1 then return 1
        if (n <= 1)
            return 1;

        //* if ans already present then return 
        if (dp[n] != -1)
            return dp[n];


        int ans = 0;
        //* iterate all node from 1 to n
        for (int i = 1; i <= n; i++) {
            //* Find left and right ans then multiply them to get total no. of possible ans when there total is i node
            //* And accumulate them in ans variable
            ans += solveRec(i-1, dp) * solveRec(n-i, dp);
        }

        //* store ans in dp array and return it
        return dp[n] = ans;
    }
public:
    int numTrees(int n) {
        vector<int> dp(n+1, -1);
        return solveRec(n, dp);
    }
};