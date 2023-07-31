#include <iostream>
using namespace std;

void merge(int *arr, int s, int e)
{
	int mid = s + (e - s) / 2;

	// lengths of 2 sub array
	int len1 = mid - s + 1;
	int len2 = e - mid;

	// making 2 sub array using heap memory
	int *first = new int[len1];
	int *second = new int[len2];

	// put the first part into first array
	int k = s;
	for (int i = 0; i < len1; i++)
	{
		first[i] = arr[k++];
	}

	// store the second part into second array
	for (int i = 0; i < len2; i++)
	{
		second[i] = arr[k++];
	}

	// merging of 2 sub array with sorting
	int index1 = 0;
	int index2 = 0;
	k = s;

	while (index1 < len1 && index2 < len2)
	{
		if (first[index1] < second[index2])
			arr[k++] = first[index1++];

		else
			arr[k++] = second[index2++];
	}

	while (index1 < len1)
	{
		arr[k++] = first[index1++];
	}

	while (index2 < len2)
	{
		arr[k++] = second[index2++];
	}

	// deleting array from heap memory
	delete[] first;
	delete[] second;
}

// TIME COMPLEXITY  --> O(n*log n)
// SPACE COMPLEXITY --> O(n)
void mergeSort(int *arr, int s, int e)
{
	if (s >= e)
	{
		return;
	}

	int mid = s + (e - s) / 2;

	// sorting left part
	mergeSort(arr, s, mid);

	// sorting right part
	mergeSort(arr, mid + 1, e);

	// merging 2 array into main array with sorting
	merge(arr, s, e);
}

int main()
{
	int arr[] = {2, 6, 88, 24, 61, 9, 15};
	int n = sizeof(arr) / sizeof(int);

	mergeSort(arr, 0, n - 1);

	for (int i : arr)
		cout << i << "  ";
	cout << endl;

	return 0;
}