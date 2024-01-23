//? https://leetcode.com/problems/longest-common-subsequence/description/

//! m -> length of text1 & n -> length of text2
//! T.C -> O(m*n)
//! S.C -> O(m*n)

//* Recursion + Memoization

#include <bits/stdc++.h> 
using namespace std;

class Solution {
    //! i points to index of string a
    //! j points to index of string b
    int solveMem(string& a, string& b, int i, int j, vector<vector<int>>& dp) {
        //* if there is no element in a OR b then return 0
        if (i >= a.length() || j >= b.length())
            return 0;

        //* if already have ans then return it
        if (dp[i][j] != -1)
            return dp[i][j];

        //* it store length of longest common subsequences
        int ans = 0;
        //* char at index i of a AND char at index j of b are equal then we include it
        if (a[i] == b[j]) {
            //* include character which is equal
            //* Size will be 1 + Size of Remaining subsequences
            ans = 1 + solveMem(a, b, i+1, j+1, dp);
        }

        //* if both char are not matched then 
        else {
            //* find ans with skip ith element, jth ele will remain same
            //* and find ans with skip jth element, jth ele will remain same

            //* store max of both ans in ans variable
            ans = max(solveMem(a, b, i+1, j, dp), solveMem(a, b, i, j+1, dp));
        }

        //* store in dp and return ans
        return dp[i][j] = ans;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(), vector<int> (text2.length(), -1));
        return solveMem(text1, text2, 0, 0, dp);
    }
};