//? https://leetcode.com/problems/pizza-with-3n-slices/description/

//? k -> size of array
//! T.C -> O(k*k)
//! S.C -> O(k*k)

//* Recursion + Memoization

#include <bits/stdc++.h> 
using namespace std;

class Solution {

    //! startingIndex -> point to start of array
    //! endIndex -> point to last index of array
    //! n -> maximum number of slices that we can eat

    int solveMem(int startIndex, int endIndex, vector<int>& slices, int n, vector<vector<int>>& dp) {
        //* base case -> if there is no remaining slice to take || traversed all slices
        if (n == 0 || startIndex > endIndex)
            return 0;

        if (dp[startIndex][n] != -1)
            return dp[startIndex][n];

        //* if we eat curr slice then
        //*  - We cant eat next slice so recursive call with startIndex->startIndex+2
        //*  - after eating curr slice then remaining slice to eat will be n-1
        int take = slices[startIndex] + solveMem(startIndex+2, endIndex, slices, n-1, dp);

        //* if we not eat curr slice then
        //*  - We can eat next slice so recursive call with startIndex->startIndex+1
        //*  - remaining slice to eat i.e. 'n' remain same
        int notTake = solveMem(startIndex+1, endIndex, slices, n, dp);

        //* After finding the both possibility value (i.e. if we eat curr slice OR not)
        //* return max of both possibility
        return dp[startIndex][n] = max(take, notTake);
    }

public:
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();

        //* If we start from 0th index then we cant eat last slice because
        //* In case we eat 0th slice then Alice eat the last slice so we no need to process it
        vector<vector<int>> dp1(k, vector<int> ((k/3)+1, -1));
        int case1 = solveMem(0, k-2, slices, k/3, dp1);

        //* If we start from 1th index then we can eat last slice because
        //* so we traverse till lase slice
        vector<vector<int>> dp2(k, vector<int> ((k/3)+1, -1));
        int case2 = solveMem(1, k-1, slices, k/3, dp2);

        //* return max of both case
        return max(case1, case2);
    }
};