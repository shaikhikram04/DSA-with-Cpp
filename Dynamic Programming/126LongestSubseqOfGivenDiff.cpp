//? https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/

//! T.C -> O(n * log(n))
//! S.C -> O(n)

//* Tabulation

#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int ans = 0;
        //* to store ans in dp.second when last value dp.first
        unordered_map<int, int> dp;

        //* Iterate each element 
        for (int i = 0; i < arr.size(); i++) {
            //* finding prev num of curr num with given difference
            int prevNum = arr[i] - difference;
            //* Store ans when last element of seq is curr element
            int temp = 1;
            //* Checking that is we have ans of prevNum
            if (dp.count(prevNum)) 
                temp += dp[prevNum]; //* If we have then update temp as add it in temp

            //* store curr ans in dp hashing
            dp[arr[i]] = temp;
            //* update ans if curr length is maximum than ans
            ans  = max(ans, temp);
        }

        //* return length of max seq
        return ans;
    }
};