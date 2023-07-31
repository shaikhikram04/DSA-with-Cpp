#include <iostream>
#include <vector>
using namespace std;

int arr_sum(int arr[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
}

int Book_allocation(int arr[], int size, int stu)
{
	int start = 0;
	int end = arr_sum(arr, size);
	int mid;
	int sum1;
	int ans;
	while (start <= end)
	{
		mid = (start + end) / 2;
		int i = 0;
		for (int m = 1; m < stu; m++)
		{
			sum1 = 0;
			while (sum1 + arr[i] <= mid)
			{
				sum1 += arr[i];
				i++;
			}
		}
		sum1 = 0;
		while (i < size)
		{
			sum1 += arr[i];
			i++;
		}
		ans=mid;
		if (sum1 > mid)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return ans;
}

int main()
{
	int arr[] = {10, 20, 30, 40};
	//int arr[] = {12, 34, 67, 90};
	int size = sizeof(arr) / sizeof(int);
	cout << Book_allocation(arr, size, 2);
	return 0;
}