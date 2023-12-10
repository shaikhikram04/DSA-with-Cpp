//? https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1

//! T.C -> O(n*m)
//! S.C -> O(n*m)

//* Recursion + Memoization

#include <bits/stdc++.h> 
using namespace std;

class Solution{
    int solveMem(vector<vector<int>>& matrix, int i, int j, int &maxi, vector<vector<int>> &dp) {
        if (i >= matrix.size() || j >= matrix[0].size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int right = solveMem(matrix, i, j+1, maxi, dp);
        int diagonal = solveMem(matrix, i+1, j+1, maxi, dp);
        int down = solveMem(matrix, i+1, j, maxi, dp);

        int ans;
        if (matrix[i][j] == 1) {
            dp[i][j] = 1 + min(right,min(diagonal, down));
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];
        }
        else
            return dp[i][j] = 0;

    }
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxi = 0;
        vector<vector<int>> dp(n, vector<int> (m, -1));
        solveMem(mat, 0, 0, maxi, dp);
        
        return maxi;
    }
};