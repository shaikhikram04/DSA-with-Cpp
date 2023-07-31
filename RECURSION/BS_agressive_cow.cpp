#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(vector<int> stall, int cow, int mid)
{
    int cowCount = 1;
    int lastPosi = stall[0];

    for (int i = 0; i < stall.size(); i++)
    {
        if (stall[i] - lastPosi >= mid)
        {
            cowCount++;
            if (cowCount == cow)
                return true;
            lastPosi = stall[i];
        }
    }
}

int agressive_cow(vector<int> stall, int cow, int s, int e, int &ans)
{
    if (s >= e)
    {
        return ans;
    }

    int mid = s + (e - s) / 2;
    if (isPossible(stall, cow, mid))
    {
        ans = mid;
        return agressive_cow(stall, cow, mid + 1, e, ans);
    }
    else
    {
        return agressive_cow(stall, cow, s, mid - 1, ans);
    }
}

int main()
{
    vector<int> stall = {4, 2, 1, 3, 6};
    int s = 0;
    sort(stall.begin(), stall.end());
    int e = stall[stall.size() - 1];
    int ans = -1;
    int cow = 2;

    cout << agressive_cow(stall, cow, s, e, ans) << endl;

    return 0;
}