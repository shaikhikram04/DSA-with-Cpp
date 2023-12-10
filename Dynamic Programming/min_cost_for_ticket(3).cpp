//! T.C -> O(n)
//! S.C -> O(1)

//* Space Optimization

#include <bits/stdc++.h> 
using namespace std;

int solveSO(vector<int>& days, vector<int>& costs) {
    queue<pair<int, int>> weekly;
    queue<pair<int, int>> monthly;

    int ans = 0;

    for (int day : days) {
        //* step-1 : remove expire day from queue
        while(!weekly.empty() && weekly.front().first + 7 <= day)
            weekly.pop();

        while(!monthly.empty() && monthly.front().first + 30 <= day)
            monthly.pop();

        //* step-2 : push curr day cost
        weekly.push({day, ans+costs[1]});
        monthly.push({day, ans+costs[2]});

        //* step-3 : ans update
        ans = min(ans + costs[0], min(weekly.front().second, monthly.front().second));
    }
    return ans;
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    return solveSO(days, cost);
}