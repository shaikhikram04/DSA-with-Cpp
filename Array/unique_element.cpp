#include <iostream>
using namespace std;

void get_unique(int arr[], int size)
{
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
				count++;
			}
		}
		if (count == 0)
		{
			cout << arr[i] << "  ";
		}
	}
}

int main()
{
	int arr[] = {1, 3, 5, 8, 0, 6, 5, 3, 2};
	int size = sizeof(arr) / sizeof(int);
	get_unique(arr, size);
	return 0;
}