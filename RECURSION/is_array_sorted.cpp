#include <iostream>
using namespace std;

// TIME COMPLEXITY  --> O(n)
// SPACE COMPLEXITY --> O(n)
bool isSorted(int arr[], int n)
{
	// base case
	if (n == 0 || n == 1)
		return true;
		
	if (arr[0] > arr[1])
		return false;
		
	return isSorted(arr+1,n-1);
}

int main()
{
	int arr[] = {1, 4, 11, 11, 12, 17};
	int len = sizeof(arr) / sizeof(int);

	if (isSorted(arr, len))
		cout << "SORTED" << endl;
	else
		cout << "NOT SORTED" << endl;

	return 0;
}