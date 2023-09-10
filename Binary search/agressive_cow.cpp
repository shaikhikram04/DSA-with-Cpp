#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ispossible(vector<int> arr, int cow, int mid)
{
	int cowCount = 1;
	int lastposi = arr[0];
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] - lastposi >= mid)
		{
			cowCount++;
			if (cowCount == cow)
				return true;
			lastposi = arr[i];
		}
	}
	return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int start = 0;
	int end = stalls[stalls.size()-1];
    int ans;

	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (ispossible(stalls, k, mid)) {
            start = mid + 1;
            ans = mid;
        }
        else {
            end = mid - 1;
        }
    }
	return ans;
}

int main()
{
	vector<int> arr = {4, 2, 1, 3, 6};
	cout << aggressiveCows(arr, 2);
	return 0;
}