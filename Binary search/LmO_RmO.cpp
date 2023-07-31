#include <iostream>
#include <cstring>
#include <array>
using namespace std;

int LeftMostOccurance(int arr[], int n, int k)
{
	int LmO;
	int start = 0;
	int last = n - 1;
	while (start <= last)
	{
		int middle = (start + last) / 2;
		if (arr[middle] == k)
		{
			LmO = middle;
			last = middle - 1;
			continue;
		}
		else if (arr[middle] > k)
		{
			last = middle - 1;
		}
		else
		{
			start = middle + 1;
		}
	}
	return LmO;
}

int RightMostOccurance(int arr[], int n, int k)
{
	int RmO;
	int start = 0;
	int last = n - 1;
	while (start <= last)
	{
		int middle = (start + last) / 2;
		if (arr[middle] == k)
		{
			RmO = middle;
			start = middle + 1;
			continue;
		}
		else if (arr[middle] > k)
		{
			last = middle - 1;
		}
		else
		{
			start = middle + 1;
		}
	}
	return RmO;
}

int main()
{
	int arr[] = {1, 2, 3, 3, 3, 3, 3, 3, 3, 5};
	int n = sizeof(arr) / sizeof(int);
	cout << LeftMostOccurance(arr, n, 3) << endl;
	cout << RightMostOccurance(arr, n, 3) << endl;
	return 0;
}