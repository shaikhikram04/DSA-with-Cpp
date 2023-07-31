#include <iostream>
using namespace std;

int minElement(int *arr, int size)
{
	int index;
	int mini = INT_FAST32_MAX;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < mini)
		{
			index = i;
			mini = arr[i];
		}
	}
	return index;
}

// TIME COMPLEXITY  --> O(n)
// SPACE COMPLEXITY --> O(n)
void selectionSort(int *arr, int size)
{
	// base case - already sorted
	if (size == 0 || size == 1)
	{
		return;
	}

	int index = minElement(arr, size);
	if (arr[0] != arr[index])
	{
		swap(arr[0], arr[index]);
	}

	selectionSort(arr + 1, size - 1);
}

int main()
{
	int arr[]={64,25,12,22,11};
	//int arr[] = {6, 2, 4, 8, 10};
	int size = sizeof(arr) / sizeof(int);

	selectionSort(arr, size);

	for (int i : arr)
		cout << i << " ";
	cout << endl;

	return 0;
}