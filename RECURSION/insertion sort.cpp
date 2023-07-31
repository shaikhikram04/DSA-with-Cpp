#include <iostream>
using namespace std;

// TIME COMPLEXITY  --> O(n)
// SPACE COMPLEXITY --> O(n)
void insertionSort(int *arr, int size, int i)
{
	if (i >= size)
	{
		return;
	}

	int temp = arr[i];
	int j;
	for (j = i - 1; j >= 0; j--)
	{
		if (temp < arr[j])
			arr[j + 1] = arr[j];

		else
			break;
	}
	arr[j + 1] = temp;

	insertionSort(arr, size, i + 1);
}

int main()
{
	int arr[] = {10, 1, 7, 4, 8, 2, 11};
	int size = sizeof(arr) / sizeof(int);

	insertionSort(arr, size, 1);

	for (int i : arr)
		cout << i << "  ";
	cout << endl;

	return 0;
}