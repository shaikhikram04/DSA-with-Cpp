#include <iostream>
using namespace std;

// not completed
int LeftMostOccurance(int *arr, int s, int e, int k)
{
	int mid = (s + e) / 2;
	
	if (s >= e)
	{
		if (arr[s] == k)
			return s;
			
		else if (arr[e] == k)
			return e;
	}
	if (arr[mid] < k)
	{
		return LeftMostOccurance(arr, mid + 1, e, k);
	}
	if (arr[mid] > k)
	{
		return LeftMostOccurance(arr, s, mid - 1, k);
	}
	if (arr[mid] == k)
	{
		return LeftMostOccurance(arr, s, mid - 1, k);
	}
}

int RightMostOccurance(int *arr, int s, int e, int k)
{
	int mid = (s + e) / 2;

	if (s == e)
	{
		if (arr[s] == k)
			return s;
			
		else if (arr[e] == k)
			return e;
	}

	if (arr[mid] < k)
	{
		return RightMostOccurance(arr, mid + 1, e, k);
	}
	if (arr[mid] > k)
	{
		return RightMostOccurance(arr, s, mid - 1, k);
	}
	if (arr[mid] == k)
	{
		return RightMostOccurance(arr, mid + 1, e, k);
	}
}

int main()
{
	int arr[] = {1, 2, 3, 3, 3, 3, 3, 3, 3, 5};
	int n = sizeof(arr) / sizeof(int);
	int k = 3;

	cout << LeftMostOccurance(arr, 0, n - 1, k) << endl;
	cout << RightMostOccurance(arr, 0, n - 1, k) << endl;
	return 0;
}