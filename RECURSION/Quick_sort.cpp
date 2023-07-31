#include <iostream>
using namespace std;

int partition(int *arr, int s, int e)
{
	int pivot = arr[s];
	int cnt = 0;
	for (int i = s + 1; i <= e; i++)
	{
		if (arr[i] < pivot)
			cnt++;
	}

	int pivotIndex = s + cnt;
	swap(arr[s], arr[pivotIndex]);

	int i = s, j = e;
	while (i < pivotIndex && j > pivotIndex)
	{
		while (arr[i] < pivot)
		{
			i++;
		}
		while (arr[j] > pivot)
		{
			j--;
		}
		if (i < pivotIndex && j > pivotIndex)
		{
			swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}

int partitionUpdate(int *arr, int s, int e) {
	int pivot = s;
	
	s++;
	while (s <= e) {
		while (arr[s] < arr[pivot]) 
			s++;

		while (arr[e] > arr[pivot])
			e--;
		
		if (s < e)
			swap(arr[s++], arr[e--]);
	}

	swap(arr[pivot], arr[e]);

	return e;
}



// TIME COMPLEXITY  --> O(n*log n)
// SPACE COMPLEXITY --> O(n)
void quickSort(int *arr, int s, int e)
{
	if (s >= e)
		return;

	int p = partitionUpdate(arr, s, e);

	quickSort(arr, s, p - 1);

	quickSort(arr, p + 1, e);
}

int main()
{
	int arr[] = {38, 27, 43, 3, 9, 82, 10};

	int size = sizeof(arr) / sizeof(int);

	quickSort(arr, 0, size - 1);

	for (int i : arr)
		cout << i << "  ";
	cout << endl;

	return 0;
}