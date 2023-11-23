//! T.C -> O(n)
//! S.C -> O(1)

//* Space Optimization

#include <bits/stdc++.h> 
using namespace std;

class Solution {
    int solve(vector<int> &nums, int n, int index) {
        
        int prev1 = 0;
        int prev2 = nums[index];

        for (int i = index+1; i < n; i++) {
            int ans = max(prev1 + nums[i] , prev2);
            prev1 = prev2;
            prev2 = ans;
        }
        return prev2;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        //* for only one house
        if (n == 1)
            return nums[0];

        //* if first inc and last exc
        int firstInc = solve(nums, n-1, 0);

        //* if first exc and last inc
        int lastInc = solve(nums, n, 1);

        return max(firstInc, lastInc);
    }
};