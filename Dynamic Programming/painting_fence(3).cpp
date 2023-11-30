//! T.C -> O(n)
//! S.C -> O(1)

//* Space Optimization

#include <bits/stdc++.h> 
using namespace std;

#define mod 1000000007

int add(int a, int b) {
    return (a%mod + b%mod)%mod;
}

int mul(int a, int b) {
    return (a%mod * 1LL * b% mod)%mod;
}

int solveSO(int n, int k) {
    int prev1 = k;
    int prev2 = k*k;

    for (int i = 3; i <= n; i++) {
        int ans = mul(add(prev1, prev2), k-1);
        prev1 = prev2;
        prev2 = ans;
    }

    return prev2;
}

int numberOfWays(int n, int k) {
    return solveSO(n, k);
}