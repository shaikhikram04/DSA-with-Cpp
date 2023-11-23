//! T.C -> O(n)
//! S.C -> O(n)

//* Tabulation

#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

long long int solveTab(int n) {
    
    vector<long long int> dp(n+1);

    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++) {
        dp[i] = ((i-1) * (dp[i-1] + dp[i-2])) % mod;
    }

    return dp[n];
}

long long int countDerangements(int n) {

    return solveTab(n);
} 