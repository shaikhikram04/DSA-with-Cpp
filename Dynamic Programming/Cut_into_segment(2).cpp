//! T.C -> O(n)
//! S.C -> O(n)

//* Tabulation

#include <bits/stdc++.h>
using namespace std;

int solveTab(int n, int x, int y, int z)
{
    //* creating dp array
    vector<int> dp(n + 1, INT_MIN);

    //* analysis and store base case
    dp[0] = 0;

    //* solve for 1-n length rod
    for (int i = 1; i <= n; i++)
    {
        if ((i - x) >= 0 && dp[i - x] != INT_MIN)
            dp[i] = max(1 + dp[i - x], dp[i]);

        if ((i - y) >= 0 && dp[i - y] != INT_MIN)
            dp[i] = max(1 + dp[i - y], dp[i]);

        if ((i - z) >= 0 && dp[i - z] != INT_MIN)
            dp[i] = max(1 + dp[i - z], dp[i]);
    }

    return dp[n];
}

int cutSegments(int n, int x, int y, int z)
{
    int ans = solveTab(n, x, y, z);

    if (ans < 0)
        return 0;

    return ans;
}