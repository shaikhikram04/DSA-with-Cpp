//! T.C -> O(n)
//! S.C -> O(1)

//* Space Optimization

#include <bits/stdc++.h> 
using namespace std;

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();

    if (n == 1)
        return nums[0];

    int nonAdj = nums[n-1];
    int adj = max(nums[n-2], nonAdj);

    for (int i = n-3; i >= 0; i--) {
        int ans = max(nonAdj+nums[i] , adj);

        nonAdj = adj;
        adj = ans;
    }
    return adj;
}