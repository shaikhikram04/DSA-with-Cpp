#include <iostream>
#include <array>
using namespace std;

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "  ";
	}
}

void sortOne(int arr[], int size)
{
	int start = 0, last = size - 1;
	while (start < last)
	{
		if (arr[start] == 0)
			start++;
		if (arr[last] == 1)
			last--;

		if (arr[start] == 1 && arr[last] == 0)
		{
			swap(arr[start], arr[last]);
			start++;
			last--;
		}
	}
	printArray(arr, size);
}

int main()
{
	int arr[] = {1, 1, 0, 0, 0, 1, 0, 1};
	int size = sizeof(arr) / sizeof(int);
	sortOne(arr, size);

	return 0;
}