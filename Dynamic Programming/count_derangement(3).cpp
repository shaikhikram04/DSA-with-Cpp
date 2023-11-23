//! T.C -> O(n)
//! S.C -> O(1)

//* Space Optimization

#include <bits/stdc++.h> 
using namespace std;

#define mod 1000000007

long long int solve(int n) {
    

    long long int prev1 = 0;
    long long int prev2 = 1;

    for (int i = 3; i <= n; i++) {
        long long int ans = ((i-1) * (prev1 + prev2)) % mod;

        prev1 = prev2;
        prev2 = ans;
    }

    return prev2;
}

long long int countDerangements(int n) {

    return solve(n);
} 