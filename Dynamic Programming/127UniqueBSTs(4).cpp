//! T.C -> O(n)
//! S.C -> O(1)

//* Simplify formula of Catalan Number then solve
//? Formula for nth catalan number -> (2n)! / ((n+1)! * n!)
//? In formula, Since  2n! / n! = (2n)(2n−1)(2n−2)....(n+1)
//* So for each first we calculate 2n! / n! also simulteneously we devide it by n+1(remaining part to calculate)

#include <cmath>

class Solution {
public:
    int numTrees(int n) {
        double catalan = 1;
        for (int i = 0; i < n; ++i) {
            catalan *= (2 * n - i);
            catalan /= (i + 1);
        }

        return static_cast<int>(round(catalan / (n + 1)));
    }
};
