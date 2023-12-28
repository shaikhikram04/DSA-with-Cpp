//! T.C -> O(k*k)
//! S.C -> O(k)

//* Space Optimization

#include <bits/stdc++.h> 
using namespace std;

#define mod 1000000007

class Solution {

    int solveSO(int n, int k, int target) {
        vector<int> prev(target+1, 0);

        prev[0] = 1;

        for (int dice = 1; dice <= n; dice++) {
            for (int tar = target; tar >= 0; tar--) {
                int ans = 0;
                for (int i = 1; i <= k && i <= tar; i++) {
                    ans = (ans + prev[tar-i]) % mod;
                }
                prev[tar] = ans;
            }
        }

        return prev[target];
    }


public:
    int numRollsToTarget(int n, int k, int target) {

        return solveSO(n, k, target);
    }
};