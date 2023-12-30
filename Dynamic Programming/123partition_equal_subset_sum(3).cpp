//! T.C -> O(n*sum)
//! S.C -> O(sum)

//* Space Optimization

#include <bits/stdc++.h> 
using namespace std;

class Solution {

    bool solveSO(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int sum = 0;
        for (int i : nums)
            sum += i;

        //* if total sum is odd
        if (sum & 1)
            return false;

        int n = nums.size();
        vector<int> next(sum/2+1, false);
        next[0] = true;

        for (int index = n-1; index >= 0; index--) {
            int temp = nums[index];
            for (int tarSum = sum/2; tarSum >= 0; tarSum--) {
                //* include
                if (tarSum-temp >= 0 && next[tarSum-temp]) {
                    next[tarSum] = true;
                    continue;
                }

                //* exclude
                if (next[tarSum]) {
                    next[tarSum] = true;
                }
            }
        }
        return next[sum/2];
    }

public:
    bool canPartition(vector<int>& nums) {
        return solveSO(nums);
    }   
};