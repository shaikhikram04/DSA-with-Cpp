//? https://www.codingninjas.com/studio/problems/count-derangements_873861?leftPanelTab=0&leftPanelTabValue=SUBMISSION

//! T.C -> O(n)
//! S.C -> O(n)

//* Recursion + Memoization

#include <bits/stdc++.h> 
#define mod 1000000007
using namespace std;

long long int solveRecMem(int n, vector<long long int> &dp) {
    // base case
    if (n == 1)
        return 0;
    
    if (n == 2)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    long long int ans = (n-1) * (solveRecMem(n-1, dp) + solveRecMem(n-2, dp) );

    dp[n] = ans % mod;

    return dp[n];
}

long long int countDerangements(int n) {

    vector<long long int> dp(n+1, -1);

    return solveRecMem(n, dp);
}