#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr_max(vector<int> arr)
{
	int maxi = INT32_MIN;
	for (int i = 0; i < arr.size(); i++)
	{
		maxi = max(arr[i], maxi);
	}
	return maxi;
}

int arr_min(vector<int> arr)
{
	int mini = INT32_MAX;
	for (int i = 0; i < arr.size(); i++)
	{
		mini = min(arr[i], mini);
	}
	return mini;
}

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

int agressive_cow(vector<int> arr, int cow)
{
	int start = 0;
	int end = arr_max(arr) - arr_min(arr);
	int mid;

	sort(arr.begin(), arr.end());
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (ispossible(arr, cow, mid))
			start = mid + 1;
		else
			end = mid - 1;
	}
	return mid;
}

int main()
{
	vector<int> arr = {4, 2, 1, 3, 6};
	cout << agressive_cow(arr, 2);
	return 0;
}