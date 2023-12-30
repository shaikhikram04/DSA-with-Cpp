//! T.C -> O(n*target)
//! S.C -> O(target)

//* Space Optimization

#include <bits/stdc++.h> 
using namespace std;

#define mod 1000000007

class Solution {

    int solveSO(int n, int k, int target) {
        //* all value with n dices depending upon values with n-1 dies
        //* So we can space optimize tabulation approach using only one array

        vector<int> prev(target+1, 0);

        prev[0] = 1;

        for (int dice = 1; dice <= n; dice++) {
            //* If we start traversing from 0 to target then prev array will overwrite values 
            //* which will use to find remaining values for current dice
            //* Therefore we start traversing from target to 0
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