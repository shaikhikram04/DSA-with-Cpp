#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int max_element(int arr[], int size)
{
	int maxi = INT_MIN;
	for (int i = 0; i < size; i++)
	{
		maxi = max(maxi, arr[i]);
	}
	return maxi;
}

int min_element(int arr[], int size)
{
	int mini = INT_MAX;
	for (int i = 0; i < size; i++)
	{
		mini = min(mini, arr[i]);
	}
	return mini;
}

bool get_unique(vector<int> arr)
{
	int size = arr.size();
	int count;
	for (int i = 0; i < size; i++)
	{
		count = 0;
		for (int j = 0; j < size; j++)
		{
			if (j == i)
			{
				continue;
			}
			if (arr[i] == arr[j])
			{
				return 0;
			}
		}
	}
	return 1;
}

bool isUniqueOccurrance(int arr[], int size)
{
	vector<int> check;
	int count;
	int mini = min_element(arr, size);
	int maxi = max_element(arr, size);
	for (int i = mini; i <= maxi; i++)
	{
		count = 0;
		for (int j = 0; j < size; j++)
		{
			if (arr[j] == i)
			{
				count++;
			}
		}
		if (count > 0)
		{
			check.push_back(count);
		}
	}
	int unique = get_unique(check);
	return unique;
}

int main()
{
	int arr[] = {1, 2, 1, 1, 2, 3};
	int size = sizeof(arr) / sizeof(int);
	int unique = isUniqueOccurrance(arr, size);
	if (unique)
		cout << "Occurrance is unique" << endl;
	else
		cout << "Occurrance is not unique" << endl;
	return 0;
}