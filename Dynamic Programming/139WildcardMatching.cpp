//? https://leetcode.com/problems/wildcard-matching/description/

//! T.C -> O(n*m)
//! S.C -> O(n*m)

//* Recursion + Memoization

#include <bits/stdc++.h> 
using namespace std;

class Solution {
    //! i -> pointed to index of s
    //! j -> pointed to index of p
    bool solve(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
        //! base case
        //* if we completely traversed both strings then return true
        if (i >= s.length() && j >= p.length())
            return true;
        //* if completely traversed p but not s then return false
        if (i < s.length() && j >= p.length())
            return false;
        //* If completely traversed s but not p then,
        if (i >= s.length() && j < p.length()) {
            //* Search in remaining part of traverse
            //* if any of char from that part is not * then return false
            for (int k = j; k < p.length(); k++) {
                if (p[k] != '*')
                    return false;
            }
            //* Otherwise return true because we can replace * with empty string
            return true;
        }

        //! If result of curr i & j is already present in dp then return it
        if (dp[i][j] != -1)
            return dp[i][j];

        //* if ith char of s & jth char of p are matched  OR jth char of p is '?'(we can replace it to any char) 
        //* then solve for remaining strings i.e. i+1 & j+1
        if (s[i] == p[j] || p[j] == '?')
            return dp[i][j] = solve(s, p, i+1, j+1, dp);
        //* If jth char of p is '*' then 
        if (p[j] == '*') 
            //* then we will replace * with empty string OR with *$($ -> ith character of s)
            return dp[i][j] = (solve(s, p, i, j+1, dp) || solve(s, p, i+1, j, dp));

        //*!If no match of character then return false
        return dp[i][j] = false;
    }

public:
    bool isMatch(string& s, string& p) {
        vector<vector<int>> dp(s.length(),vector<int> (p.length(), -1));

        return solve(s, p, 0, 0, dp);
    }
};