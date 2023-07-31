#include <iostream>
using namespace std;

int peakValue(int *arr, int s, int e)
{
	int mid = s + (e - s) / 2;
	if (arr[mid - 1] < arr[mid] && arr[mid + 1] < arr[mid])
	{
		return arr[mid];
	}

	if (arr[mid - 1] < arr[mid] && arr[mid + 1] > arr[mid])
	{
		return peakValue(arr, mid + 1, e);
	}

	if (arr[mid - 1] > arr[mid] && arr[mid + 1] < arr[mid])
	{
		return peakValue(arr, s, mid - 1);
	}
}

int main()
{
	//int arr[] = {1, 3, 4, 6, 2, 0};
	//int arr[]= {5, 10, 20, 15};
	int arr[] = {10, 20, 15, 2, 23, 90, 67};

	int n = sizeof(arr) / sizeof(int);

	cout << "Peak value --> " << peakValue(arr, 0, n - 1);

	return 0;
}