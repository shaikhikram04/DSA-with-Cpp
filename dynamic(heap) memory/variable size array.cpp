#include <iostream>
using namespace std;

int getSum(int arr[], int n)
{
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += arr[i];
	return ans;
}

int main()
{
	int n;
	cout << "Enter size of an array : ";

	// take size of array as an input
	cin >> n;
	cout << "Enter element of an array : " << endl;

	// making an integer array of size n in the heap(dynamic) memory pointed by pointer arr
	int *arr = new int[n];

	// taking element of an array
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int sum = getSum(arr, n);
	cout << "Sum = " << sum << endl;

	return 0;
}