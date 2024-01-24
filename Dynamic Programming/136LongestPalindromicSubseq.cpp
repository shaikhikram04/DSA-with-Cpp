//? https://leetcode.com/problems/longest-palindromic-subsequence/description/

//! T.C -> O(n^2)
//! S.C -> O(n^2)

//* Recursion + Memoization

#include <bits/stdc++.h> 
using namespace std;

class Solution {
    //! i -> points to pallindrome char of string s from starting
    //! j -> points to pallindrome char of string s from end
    int solveMem(string& s, int i, int j, vector<vector<int>>& dp) {
        //* if we travell all character of given string then return 0
        //* i.e. i get greater then j
        if (i > j) {
            return 0;
        }

        //* If already have ans then return it
        if (dp[i][j] != -1)
            return dp[i][j];

        //* len store 2 if i & j pointed to different index (because there are 2 character)
        //* And in same index case it store 1 (Because there is only 1 char)
        int len = (i != j) ? 2 : 1;

        //* If both char are same
        if (s[i] == s[j]) {
            //* then include curr char length and solve for remaining string then return it.
            return dp[i][j] = len + solveMem(s, i+1, j-1, dp);
        }
        //* if char are different
        else {
            //* Then there are 2 possible ans,
            //* - by increment i.
            //* - by decrement j.
            //* return max of both
            return dp[i][j] = max(solveMem(s, i+1, j, dp), solveMem(s, i, j-1, dp));
        }
    }
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solveMem(s, 0, n-1, dp);
    }
};