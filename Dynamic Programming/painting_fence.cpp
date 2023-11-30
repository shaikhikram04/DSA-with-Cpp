//? https://www.codingninjas.com/studio/problems/ninja-and-the-fence_3210208?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&leftPanelTabValue=PROBLEM

//! T.C -> O(n)
//! S.C -> O(n)

//* Recursion + Memoization

#include <bits/stdc++.h> 
using namespace std;

#define mod 1000000007

int add(int a, int b) {
    return (a%mod + b%mod)%mod;
}

int mul(int a, int b) {
    return (a%mod * 1LL * b% mod)%mod;
}

int solveRecMem(int n, int k, vector<int> &dp) {
    if (n == 1)
        return k;

    if (n == 2)
        return (k * k);

    if (dp[n] != -1)
        return dp[n];

    dp[n] =add(mul(solveRecMem(n-2, k, dp), k-1), mul(solveRecMem(n-1, k, dp), k-1));

    return dp[n];
}


int numberOfWays(int n, int k) {
    vector<int> dp(n+1, -1);

    return solveRecMem(n, k, dp);
}