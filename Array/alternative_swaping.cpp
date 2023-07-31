#include <iostream>
using namespace std;

void printarray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}

void swap_alternate(int arr[], int size)
{
	for (int i = 0; i<size || (i + 1) < size - 1; i += 2)
	{
		swap(arr[i], arr[i + 1]);
	}
}

int main()
{
	int num[] = {1, 2, 3, 4, 5, 6, 7, 0};
	int length = sizeof(num) / sizeof(int);
	printarray(num, length);
	swap_alternate(num, length);
	printarray(num, length);
	return 0;
}