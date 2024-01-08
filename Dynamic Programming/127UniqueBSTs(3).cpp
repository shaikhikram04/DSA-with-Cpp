//! T.C -> O(n)
//! S.C -> O(1)

//* Space Optizatation Using Formula of Catalan Number
//? Formula for nth catalan number -> (2n)! / ((n+1)! * n!)

#include <cmath>

class Solution {
    double fact(int n) {
        double ans = 1;
        for (int i = 2; i <= n; i++) {
            ans *= i;
        }
        return ans;
    }

public:
    int numTrees(int n) {
        double ans = fact(2 * n) / (fact(n + 1) * fact(n));
        return static_cast<int>(round(ans));
    }
};