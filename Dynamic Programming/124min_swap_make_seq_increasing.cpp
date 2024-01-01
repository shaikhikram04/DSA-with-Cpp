//? https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/

//! T.C -> O(n*sum)
//! S.C -> O(n*sum)

//* Recursion + Memoization

#include <bits/stdc++.h> 
using namespace std;

class Solution {
    int solveMem(vector<int>& nums1, vector<int>& nums2, int index, bool swaped, vector<vector<int>>& dp) {
        //* if array is empty then return 0
        if (index >= nums1.size())
            return 0;


        if (dp[index][swaped] != -1)
            return dp[index][swaped];

        //* find previous element of current index
        //* prev1 store previous element from nums1 array
        //* prev2 store previous element from nums2 array
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        //* if previous index swaped then 
        //* - previous of nums1 become previous of nums2
        //* - and visa versa
        //* so swap them in this case
        if (swaped)
            swap(prev1, prev2);

        //* store minimum answer 
        int ans = INT_MAX;
        
        //! swaping curr index if following condition satisfy
        //* - check that if after we swap curr index then both array will increasing till curr index
        //* - if yes then recurcively find ans oof it after swap
        if (nums1[index] > prev2 && nums2[index] > prev1) {
            //* Add 1 here in recursive call part because here we swaped so we have to add this swap count in ans
            ans = min(ans, 1 + solveMem(nums1, nums2, index+1, true, dp)); //* mark swaped as true because here we swap curr index
        }

        //! no swap curr index if following condition satisfy
        //* check that if after we not swap curr index then both array will increasing till curr index
        //* - if yes then recurcively find ans oof it after no swap
        if (nums1[index] > prev1 && nums2[index] > prev2)
            ans = min(ans, solveMem(nums1, nums2, index+1, false, dp)); //* mark swaped as false because here we not swap curr index

        //* store in dp array and return minimum of ans
        return dp[index][swaped] = ans;
    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        //* Since for each element we check for previous element to swap curr index or not 
        //* And there is no previous element present for 0th index element 
        //* Therefore we insert -1(first element will always positive so we take smaller than 0) in begining of both arrays
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        vector<vector<int>> dp(nums1.size(), vector<int> (2, -1));
        //* Start from 1 because we insert -1 at begining so our main array actually start from index 1
        //* And swaped = false because we can't swap 0th index element(prev of 1st index) because it is not a part of main array
        return solveMem(nums1, nums2, 1, false, dp);

    }
};