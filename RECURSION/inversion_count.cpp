#include <iostream>
using namespace std;


int merge(int *arr, int s, int e)
{
	int count = 0;
	int mid = s + (e - s) / 2;
	int len1 = mid - s + 1;
	int len2 = e - mid;

	int *first = new int[len1];
	int *second = new int[len2];

	int k = s;
	for (int i = 0; i < len1; i++)
	{
		first[i] = arr[k++];
	}

	for (int i = 0; i < len2; i++)
	{
		second[i] = arr[k++];
	}

	int index1 = 0;
	int index2 = 0;
	k = s;

	while (index1 < len1 && index2 < len2)
	{
		if (first[index1] < second[index2])
			arr[k++] = first[index1++];

		else
		{
			count += len1 - index1;
			arr[k++] = second[index2++];
		}
	}
	while (index1 < len1)
	{
		arr[k++] = first[index1++];
	}

	while (index2 < len2)
	{
		arr[k++] = second[index2++];
	}
	
	delete []first;
	delete []second; 
	
	
	return count;
}

// TIME COMPLEXITY  --> O(n*log n)
// SPACE COMPLEXITY --> O(n)
int inversionCount(int *arr, int s, int e)
{
	if (s >= e)
		return 0;

	int count = 0;
	int mid = s + (e - s) / 2;

	// left sub array
	count += inversionCount(arr, s, mid);

	// right sub array
	count += inversionCount(arr, mid + 1, e);

	count += merge(arr, s, e);

	return count;
}

int main()
{
	//int arr[] = {2, 6, 88, 24, 61, 9, 15};
	//int arr[] = {8,4,2,1};
	int arr[] = {38,27,43,3,9,82,10};
	
	int n = sizeof(arr) / sizeof(int);

	cout << "Inversion count --> " << inversionCount(arr, 0, n - 1) << endl;

	for (int i : arr)
		cout << i << "  ";
	cout << endl;

	return 0;
}