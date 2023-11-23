//? https://www.codingninjas.com/studio/problems/nth-fibonacci-number_74156?leftPanelTab=0

//! T.C -> O(n)
//! S.C -> O(n)

//* Recursion + Memoization

#include <bits/stdc++.h>
using namespace std;

int getNthFibonacci(int n, vector<int> &dp)
{
    //* base case
    if (n <= 1)
        return n;

    if (dp[n - 1] == -1)
        dp[n - 1] = getNthFibonacci(n - 1, dp) + getNthFibonacci(n - 2, dp); //* Recersive calls

    return dp[n - 1];
}

int main()
{
    int n;
    cin >> n;

    vector<int> dp(n, -1);

    cout << getNthFibonacci(n, dp) << endl;

    return 0;
}