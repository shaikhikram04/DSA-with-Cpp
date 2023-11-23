
//! T.C -> O(n)
//! S.C -> O(n)

//* Tabulation

#include <bits/stdc++.h> 
using namespace std;

int maximumNonAdjacentSum(vector<int> &nums){
    
    int n = nums.size();
    //* Handle 1 size array
    if (n == 1)
        return nums[0];

    //* create dp array
    vector<int> dp(n, -1);

    //* assign maxSum value for adj and non-adj for 3 last element
    dp[n-1] = nums[n-1];
    dp[n-2] = max(nums[n-2] , dp[n-1]);
    
    for (int i = n-3; i >= 0; i--) {
        dp[i] = max(nums[i]+dp[i+2] , dp[i+1]);
    }

    return dp[0];
}