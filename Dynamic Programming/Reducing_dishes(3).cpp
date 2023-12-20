//! T.C -> O(n^2)
//! S.C -> O(2*n) => O(n)

//* Space Optimization

#include <bits/stdc++.h> 
using namespace std;

class Solution {
    int solveTab(vector<int>& sat) {
        sort(sat.begin(), sat.end());

        int n = sat.size();
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);

        for (int i = n-1; i >= 0; i--) {
            for (int time = i; time >= 0; time--) {
                // include
                int inc = (time+1)*sat[i] + next[time+1];
                // exclude
                int exc = next[time];

                curr[time] = max(inc, exc);
            }
            next = curr;
        }

        return next[0];
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        return solveTab(satisfaction);
    }
};