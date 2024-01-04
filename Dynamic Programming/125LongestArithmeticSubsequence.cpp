//? https://leetcode.com/problems/longest-arithmetic-subsequence/description/

//! T.C -> O(n^2)
//! S.C -> O(n^2)

//* Tabulation

#include <bits/stdc++.h> 
using namespace std;

class Solution {

public:
    int longestArithSeqLength(vector<int>& nums) {
        //* To store ans
        int ans = 0; 
        //* size of nums array
        int n = nums.size();

        //* array of unordered_map
        //* array size n
        //* array index indicate index of nums array
        //* map.first(int) indicate difference between a number and nums[i]{i -> index of array}
        //* and map.second indicate ans when last value is nums[i] and difference is dp[i].second{map.first}
        unordered_map<int, int> dp[n];

        //* consider i as last index of seq and solve for its previous elements
        //* since there is no previous of index 0 so we start from 1
        for (int i = 1; i < n; i++) {
            //* check for if last element index is i
            //* solve for each possible previous value
            for (int j = 0; j < i; j++) {
                //* first find the difference
                int diff = nums[i] - nums[j];
                //* store length of curr seq
                int cnt = 1;

                //* if cnt already present in hash then update cnt
                //* it store ans till jth index
                if (dp[j].count(diff))
                    cnt = dp[j][diff];

                //* store cnt in hash
                //* also add 1 of including ith index
                dp[i][diff] = cnt + 1;

                //* store maximum in ans
                ans = max(ans, dp[i][diff]);
            }
        }

        //* return the maximum ans
        return ans;
    }
};