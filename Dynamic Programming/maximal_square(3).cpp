//! T.C -> O(n*m)
//! S.C -> O(m)

//* Space Optimization

#include <bits/stdc++.h> 
using namespace std;

class Solution{
    int solveSO(int n, int m, vector<vector<int>> mat) {
        vector<int> dp(m+1, 0);
        int maxi = 0;
        
        for (int i = n-1; i >= 0; i--) {
            vector<int> temp(m+1, 0);
            for (int j = m-1; j >= 0; j--) {
                int right = temp[j+1];
                int diag = dp[j+1];
                int down = dp[j];
                
                if (mat[i][j] == 1) {
                    temp[j] = 1 + min(right, min(diag, down));
                    maxi = max(maxi, temp[j]);
                }

            }
            dp = temp;
        }
        return maxi;
    }
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        return solveSO(n, m, mat);
    }
};