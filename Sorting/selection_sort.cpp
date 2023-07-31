#include <iostream>

using namespace std;

int min_arr(int arr[], int size, int initial)
{
	int mini = INT_MAX;
	int index;

	for (int i = initial; i < size; i++)
	{
		if (min(arr[i], mini) < mini)
			index = i;

		mini = min(arr[i], mini);
	}
	return index;
}

int main()
{
	//arr[]={64,25,12,22,11};
	int arr[] = {6,2,4,8,10};
	int size = sizeof(arr) / sizeof(int);
	for (int i = 0; i < size - 1; i++)
	{
		int index = min_arr(arr, size, i);
		if (arr[i] != arr[index])
		{
			swap(arr[i], arr[index]);
		}
	}
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
	return 0;
}