//! T.C -> O(n)
//! S.C -> O(1)

//* Space Optimization

#include <bits/stdc++.h> 
using namespace std;

class Solution {

    static int solveSO(vector<int>& nums1, vector<int>& nums2) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums1.size();
        vector<int> next(2, 0);
        vector<int> curr(2);

        for (int index = n-1; index >= 1; index--) {
            int prev1 = nums1[index-1];
            int prev2 = nums2[index-1];
            for (int swaped = 0; swaped <= 1; swaped++) {
                if (swaped)
                    swap(prev1, prev2);

                int ans = INT_MAX;
                // swap
                if (nums1[index] > prev2 && nums2[index] > prev1)
                    ans = 1 + next[1];

                // no swap
                if (nums1[index] > prev1 && nums2[index] > prev2)
                    ans = min(ans, next[0]);

                curr[swaped] = ans;
            }
            next = curr;
        } 
        return curr[0];
    }

public:
    constexpr static int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        return solveSO(nums1, nums2);

    }
};