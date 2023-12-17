//! T.C -> O(n)
//! S.C -> O(1)

//* Space Optimization

#include <bits/stdc++.h> 
using namespace std;

class Solution {

    int solveSO(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> prev(4, 0);
        vector<int> curr(4);

        for (int i = n-2; i >= 0; i--) {
            for (int lane = 1; lane <= 3; lane++) {
                if (obstacles[i] != lane) {
                    if (obstacles[i+1] != lane) {
                        curr[lane] = prev[lane];
                    }
                    else {
                        int ans = INT_MAX;
                        for (int l = 1; l <= 3; l++) {
                            if (l != lane && obstacles[i] != l) {
                                ans = min(ans , 1 + prev[l]);
                            }
                        }
                        curr[lane] = ans;
                    }
                }
            }
            prev = curr;
        }

        return prev[2];
    }

public:
    int minSideJumps(vector<int>& obstacles) {
        return solveSO(obstacles);
    }
};