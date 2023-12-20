//! T.C -> O(n^2)
//! S.C -> O(1)

//* More Space Optimization || Iterative

#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();

        int LTC = 0;
        for (int i = 0; i < n; i++) {
            int ltc = 0;
            for (int j = i, k = 1; j < n; j++, k++) {
                ltc += k*satisfaction[j];
            }
            LTC = max(LTC, ltc);
        }

        return LTC;
    }
};