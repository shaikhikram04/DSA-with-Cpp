//! T.C -> O(n)
//! S.C -> O(n)

//* Tabulation

#include <bits/stdc++.h> 
using namespace std;

#define mod 1000000007

int add(int a, int b) {
    return (a%mod + b%mod)%mod;
}

int mul(int a, int b) {
    return (a%mod * 1LL * b% mod)%mod;
}


int solveTab(int n, int k) {
    vector<int> dp(n+1);

    dp[1] = k;
    dp[2] = k*k;

    for (int i = 3; i <= n; i++) {
        dp[i] = add(mul(dp[i-2], k-1), mul(dp[i-1], k-1));
    }

    return dp[n];
}

int numberOfWays(int n, int k) {
    return solveTab(n, k);
}