//? https://www.codingninjas.com/studio/problems/nth-fibonacci-number_74156?leftPanelTab=0

//! T.C -> O(n)
//! S.C -> O(n)

//* Tabulation

#include <bits/stdc++.h>
using namespace std;

int getNthFibonacci(int n)
{
    //* step 1 : create table
    vector<int> dp(n + 1);
    //* step 2 : store base case
    dp[0] = 0;
    dp[1] = 1;

    //* step 3 : store remaining
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    cout << getNthFibonacci(n) << endl;

    return 0;
}