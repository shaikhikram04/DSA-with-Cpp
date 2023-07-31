#include <iostream>
using namespace std;

int pivot(int arr[], int n)
{
	int pivot_element;
	int start = 0;
	int last = n - 1;
	int mid;
	while (start <= last)
	{
		mid = (start + last) / 2;
		if (arr[mid]-arr[mid-1]<0)
		{
			pivot_element = arr[mid];
			break;
		}
		if (arr[mid]-arr[n-1]>0)
		{
			start = mid + 1;
		}

		if (arr[mid]-arr[n-1]<0)
		{
			last = mid - 1;
		}
	}
	return pivot_element;
}

int main()
{
	int arr[] = {4,5,6,7,8,1,2,3};
	int n = sizeof(arr) / sizeof(int);
	cout << pivot(arr, n) << endl;
	return 0;
}