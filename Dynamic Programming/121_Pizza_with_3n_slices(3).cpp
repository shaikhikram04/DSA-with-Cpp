
//? k -> size of array
//! T.C -> O(k*k)
//! S.C -> O(k)

//* Space Optimization

#include <bits/stdc++.h> 
using namespace std;

class Solution {

    int solveSO(int startIndex, int endIndex, vector<int>& slices) {
        int k = slices.size();
        int n = k/3;
        vector<int> prev(k+2, 0);
        vector<int> curr(k+2, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = endIndex; j >= startIndex; j--) {
                int take = slices[j] + prev[j+2];
                int notTake = curr[j+1];

                curr[j] = max(take, notTake);
            }
            prev = curr;
        }
        return prev[startIndex];
    }

public:
    int maxSizeSlices(vector<int>& slices) {

        int k = slices.size();

        int case1 = solveSO(0, k-2, slices);

        int case2 = solveSO(1, k-1, slices);

        return max(case1, case2);
    }
};