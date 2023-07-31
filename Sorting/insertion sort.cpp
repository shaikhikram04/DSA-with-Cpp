#include <iostream>
using namespace std;

void insertion_sort(int arr[], int size)
{
	for (int i = 1; i < size; i++)
	{
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
	}
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	int arr[] = {10, 1, 7, 4, 8, 2, 11};
	int size = sizeof(arr) / sizeof(int);
	insertion_sort(arr, size);
	return 0;
}