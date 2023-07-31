#include <iostream>
using namespace std;

// TIME COMPLEXITY  --> O(n)
// SPACE COMPLEXITY --> O(n)
int sumArray(int arr[], int len)
{
	if (len == 0)
		return 0;

	if (len == 1)
		return arr[0];

	int sum = arr[0] + sumArray(arr + 1, len - 1);

	return sum;
}

int main()
{
	int arr[] = {3, 2, 5, 1, 6};
	int len = sizeof(arr) / sizeof(int);

	cout << "Sum of array is " << sumArray(arr, len) << endl;

	return 0;
}