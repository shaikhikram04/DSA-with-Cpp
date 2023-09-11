#include <iostream>
using namespace std;

// TIME COMPLEXITY  --> O(log n) 
// SPACE COMPLEXITY --> O(log n)
bool binarySearch(int *arr, int s, int e, int key)
{
	if (s > e)
	{
		return false;
	}
	int mid = (s + e) / 2;

	if (arr[mid] == key)
	{
		return true;
	}
	if (arr[mid] < key)
	{
		return binarySearch(arr, mid + 1, e, key);
	}
	else
	{
		return binarySearch(arr, s, mid - 1, key);
	}
}

int main()
{
	int arr[] = {2, 4, 5, 7, 9, 11};
	int n = sizeof(arr) / sizeof(int);
	int key = 8;

	if (binarySearch(arr, 0, n - 1, key))
	{
		cout << "FOUND" << endl;
	}
	else
		cout << "NOT FOUND" << endl;

	return 0;
}