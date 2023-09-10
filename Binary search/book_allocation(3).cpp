#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int> arr, int p, int s, int mid)
{
	int studCount = 1;
	int pageSum = 0;
	for (int i = 0; i < p; i++)
	{
		if (pageSum + arr[i] <= mid)
		{
			pageSum += arr[i];
		}
		else
		{
			studCount++;
			if (studCount > s || arr[i] > mid)
			{
				return false;
			}
			pageSum = arr[i];
		}
	}
	return true;
}

int book_allocation(vector<int> arr, int p, int s)
{
	int start = 0;
	int sum = 0;
	int ans;
	for (int i = 0; i < p; i++)
	{
		sum += arr[i];
	}
	int end = sum;
	int mid;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (isPossible(arr, p, s, mid))
		{
			ans = mid;
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	return ans;
}

int main()
{
	// vector<int>arr = {10, 20, 30, 40};
	vector<int> arr = {12, 34, 67, 90};
	int p = 4, s = 2;
	cout << book_allocation(arr, p, s) << endl;
	return 0;
}