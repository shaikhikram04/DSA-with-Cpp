//? https://www.codingninjas.com/studio/problems/count-ways-to-reach-nth-stairs_798650?leftPanelTab=0&leftPanelTabValue=PROBLEM

//! T.C -> O(n)
//! S.C -> O(1)

#define mod 1000000007

#include <bits/stdc++.h>
 
int countDistinctWays(int nStairs) {
    if (nStairs <= 1)
        return 1;

    int prev1 = 1;
    int prev2 = 2;
    for (int i = 3; i <= nStairs; i++) {
        int curr = (prev1 + prev2) % mod;
        prev1 = prev2;
        prev2 = curr;
    }
    return prev2;
}