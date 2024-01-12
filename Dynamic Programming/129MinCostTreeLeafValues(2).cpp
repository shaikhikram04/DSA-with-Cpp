//! T.C -> O(n^4)
//! S.C -> O(n^4)

//* Tabulation

#include <bits/stdc++.h> 
using namespace std;


class Solution {
    //* Return max Element from provided subarray(from i->j)
    int getMax(vector<int>& arr, int s, int e) {
        int maxi = INT_MIN;
        for (int i = s; i <= e; i++) {
            maxi = max(maxi, arr[i]);
        }
        return maxi;
    }

    int solveTab(vector<int>& arr) {
        int n = arr.size();
        //* create dp array of n*n with all 0's
        vector<vector<int>> dp(n, vector<int> (n, 0));

        //* Solve for each subarray
        for (int start = n-1; start >= 0; start--) {
            for (int end = start+1; end < n; end++) {
                //* It store Minimum ans
                int ans = INT_MAX;
                //* Partition Leafy nodes from start to end And each partition contain 1 or more leafy nodes
                for (int i = start; i < end; i++) {
                    //* Find max leaf from left subarray and right subarray then multiply them to find the value of their parent
                    //* Also add the ans of left subarray and right subarray that is stored in dp array
                    ans = min(ans, getMax(arr,start,i)*getMax(arr,i+1,end) + dp[start][i] + dp[i+1][end]);
                }

                //* store ans in dp array
                dp[start][end] = ans;
            }
        }

        //* return ans when array is from 0 to n-1
        return dp[0][n-1];
    }

public:
    int mctFromLeafValues(vector<int>& arr) {

        return solveTab(arr);
    }
};