#include <iostream>
using namespace std;

int search_element(int arr[], int n, int k)
{
	int start = 0;
	int last = n - 1;
	int mid;
	while (start <= last)
	{
		mid = (start + last) / 2;
		if (arr[mid] == k)
			return mid;
		if (arr[mid] - arr[start] < 0)
		{
			if (k > arr[mid] && k <= arr[last])
				start = mid + 1;
			else
				last = mid - 1;
		}
		else if (arr[mid] - arr[start] >= 0)
		{
			if (k < arr[mid] && k >= arr[start])
				last = mid - 1;
			else
				start = mid + 1;
		}

	}
	return -1;
}

int main()
{
	int arr[] = {8, 1, 2, 3, 5, 7};
	// int arr[] = {4, 5, 6, 7, 0, 1, 2};
	int n = sizeof(arr) / sizeof(int);
	int k;
	cin >> k;
	cout << search_element(arr, n, k) << endl;
	return 0;
}