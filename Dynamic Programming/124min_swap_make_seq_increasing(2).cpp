//! T.C -> O(n*sum)
//! S.C -> O(n*sum)

//* Tabulation

#include <bits/stdc++.h> 
using namespace std;

class Solution {

    int solveTab(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        //* make dp array with all 0's(because of base case)
        vector<vector<int>> dp(n+1, vector<int> (2, 0));

        for (int index = n-1; index >= 1; index--) {
            int prev1 = nums1[index-1];
            int prev2 = nums2[index-1];
            for (int swaped = 0; swaped <= 1; swaped++) {
                if (swaped)
                    swap(prev1, prev2);

                int ans = INT_MAX;
                // swap
                if (nums1[index] > prev2 && nums2[index] > prev1)
                    ans = 1 + dp[index+1][1];

                // no swap
                if (nums1[index] > prev1 && nums2[index] > prev2)
                    ans = min(ans, dp[index+1][0]);

                dp[index][swaped] = ans;
            }
        } 
        return dp[1][0];
    }

public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        return solveTab(nums1, nums2);

    }
};