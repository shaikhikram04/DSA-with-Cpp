#include <iostream>
using namespace std;

// TIME COMPLEXITY  --> O(n)
// SPACE COMPLEXITY --> O(n)
bool isFound(int *arr, int len, int key)
{
	if (len == 0)
		return false;
	if (arr[0] == key)
		return true;

	return isFound(arr + 1, len - 1, key);
}

int main()
{
	int arr[] = {2, 4, 6, 1, 3, 9, 7};
	int len = sizeof(arr) / sizeof(int);
	int key = 8;

	if (isFound(arr, len, key))
		cout << "FOUND" << endl;
	else
		cout << "NOT FOUND" << endl;

	return 0;
}