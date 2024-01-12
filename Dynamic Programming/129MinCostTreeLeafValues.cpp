//? https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/

//! T.C -> O(n^4)
//! S.C -> O(n^4)

//* Recursion + Memoization

#include <bits/stdc++.h> 
using namespace std;

class Solution {
    //* Return max Element from provided subarray(from i->j)
    int getMax(vector<int>& arr, int i, int j) {
        int maxi = INT_MIN;
        for (int k = i; k <= j; k++) {
            maxi = max(maxi, arr[k]);
        }

        return maxi;
    }

    int solveMem(vector<int>& arr, int start, int end, vector<vector<int>>& dp){
        //* If there is no parent of leafy node because there is only 1 leafy node and parent is multiple of both child
        if (start == end)
            return 0;

        //* If ans is already present then return it
        if (dp[start][end] != -1)
            return dp[start][end];

        //* It store Minimum ans
        int ans = INT_MAX;
        //* Partition Leafy nodes from start to end And each partition contain 1 or more leafy nodes
        for (int k = start; k < end; k++) {
            //* Find max leaf from left subarray and right subarray then multiply them to find the value of their parent
            //* Also add the ans of left subarray and right subarray that will find using recursion
            ans = min(ans, getMax(arr,start,k)*getMax(arr,k+1,end) + solveMem(arr,start,k, dp) + solveMem(arr,k+1,end, dp));
        }

        //* store the ans in dp array return when array is from start to end
        return dp[start][end] = ans;
    }
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int> (n, -1));

        return solveMem(arr,0,n-1, dp);
    }
};