//! T.C -> O(n * m * min(n, m))
//! S.C -> O(1)

//* More Space Optimization

#include <bits/stdc++.h> 
using namespace std;

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxAns = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    int ans = 1;
                    int newi = i, newj = j;
                    while (++newi < n && ++newj < m && mat[newi][newj] == 1) {
                        bool isSquare = true;
                        //* check vertically and horizontally   
                        for (int k = 0; k <= ans; k++) {
                            if (mat[newi-k][newj] == '0') {
                                isSquare = false;
                                j = newj;
                                break;
                            }
                            else if (mat[newi][newj-k] == '0') {
                                isSquare = false;
                                break;
                            }
                        }
                        if (isSquare) {
                            ans++;
                        } else {
                            break;
                        }
                    }
                    
                    maxAns = max(maxAns, ans);

                    if (min(n-(i+1), m) <= maxAns && min(n-i, m-(j+1)) <= maxAns) {
                        return maxAns;
                    }

                    if (newj >= m)
                        break;
                        
                }
            }
        }
        return maxAns;
    }
};