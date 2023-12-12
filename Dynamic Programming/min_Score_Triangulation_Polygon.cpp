//? https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/

//! T.C -> O(n*n)
//! S.C -> O(n*n)

//* Recursion + Memoization

#include <bits/stdc++.h> 
using namespace std;

class Solution {
    int solveMem(vector<int>& v, int i, int j, vector<vector<int>> & dp) {
        //* base case : if no. of vertex is 2
        if (i+1 == j) {
            return 0;
        }

        //* return ans if already have
        if (dp[i][j] != -1)
            return dp[i][j];

        //* consider k as a 3ed vertex between i & j
        //* ans store mini possible score after iteration
        int ans = INT_MAX;
        for (int k = i+1; k < j; k++) {
            ans = min(ans, v[i]*v[j]*v[k] + solveMem(v,i,k, dp) + solveMem(v,k,j, dp)); 
        }

        //* store ans in dp array
        dp[i][j] = ans;
        //* return minimum score
        return ans;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp (n-1, vector<int> (n, -1));
        return solveMem(values, 0, n-1, dp);
    }
};