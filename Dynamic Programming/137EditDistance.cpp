//? https://leetcode.com/problems/edit-distance/description/

//! T.C -> O(n*m)
//! S.C -> O(n*m)

//* Recursion + Memoization

#include <bits/stdc++.h> 
using namespace std;

class Solution {

    //! i pointed to index of string a
    //! j pointed to index of string b
    int solveMem(string& a, string& b, int i, int j, vector<vector<int>>& dp) {
        //* if "a" string traversed completely then we have to insert remaining element of "b" in "a"
        //* So, return no. of remaining element in b
        if (i == a.length()) {
            return b.length()-j;
        }

        //* if "b" string traversed completely then we have to delete remaining element of "a".
        //* So, return no. of remaining element a
        if (j == b.length()) {
            return a.length()-i;
        }

        //* if we already have ans in dp then return it
        if (dp[i][j] != -1)
            return dp[i][j];

        //! if char match
        //* then solve for remaining strings of a and b
        if (a[i] == b[j]) {
            return dp[i][j] = solveMem(a, b, i+1, j+1, dp);
        }
        //! Not match
        else {
            //? insert
            int insertAns = 1 + solveMem(a, b, i, j+1, dp);

            //? delete
            int delAns = 1 + solveMem(a, b, i+1, j, dp);

            //? replace
            int replaceAns = 1 + solveMem(a, b, i+1, j+1, dp);

            return dp[i][j] = min(insertAns, min(delAns, replaceAns));
        }
    }

public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int> (word2.size()+1, -1));
        return solveMem(word1, word2, 0, 0, dp);
    }
};