
//! T.C -> O(n)
//! S.C -> O(1)

#include <bits/stdc++.h>
using namespace std;

int getNthFibonacci(int n)
{

    int prev1 = 0;
    int prev2 = 1;
    for (int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }
    return prev2;
}

int main()
{
    int n;
    cin >> n;

    cout << getNthFibonacci(n) << endl;

    return 0;
}