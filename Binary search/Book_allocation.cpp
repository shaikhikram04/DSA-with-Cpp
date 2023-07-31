#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int sum_arr_max(vector<int> arr1, int size1, vector<int> arr2, int size2)
{
	int sum1 = 0, sum2 = 0;
	int sum_max;
	for (int i = 0; i < size1; i++)
	{
		sum1 += arr1[i];
	}
	for (int j = 0; j < size2; j++)
	{
		sum2 += arr2[j];
	}
	sum_max = max(sum1, sum2);
	return sum_max;
}

int book_allocation(int arr[], int size, int s, int p)
{
	int min_sum = INT_MAX;
	int max_sum;
	vector<int> partition1;
	vector<int> partition2;
	for (int i = 0; i < p - 1; i++)
	{
		vector<int> partition1;
		vector<int> partition2;
		for (int j = 0; j <= i; j++)
		{
			partition1.push_back(arr[j]);
		}
		for (int k = i + 1; k < p; k++)
		{
			partition2.push_back(arr[k]);
		}
		int size1 = partition1.size();
		int size2 = partition2.size();
		max_sum = sum_arr_max(partition1, size1, partition2, size2);
		min_sum = min(min_sum, max_sum);
	}
	return min_sum;
}

int main()
{
	//int arr[] = {10, 20, 30, 40};
	int arr[] = {12, 34, 67, 90};
	int size = sizeof(arr) / sizeof(int);
	int s = 2, p = 4;
	cout << book_allocation(arr, size, s, p);
	return 0;
}