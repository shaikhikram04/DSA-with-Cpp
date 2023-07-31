#include <iostream>
using namespace std;

int peakValue(int arr[], int n)
{
	int max;
	int start = 0;
	int last = n - 1;
	int middle;
	while (1)
	{
		middle = (start + last) / 2;
		if (arr[middle - 1] < arr[middle] && arr[middle + 1] < arr[middle])
		{
			max = arr[middle];
			break;
		}
		if(arr[middle - 1] < arr[middle]){
			start=middle+1;
		}
		else if (arr[middle+1]<arr[middle]){
			last=middle-1;
		}
	}
	return max;
}

int main()
{
	int arr[]={1,3,4,6,2,0};
	int n=sizeof(arr)/sizeof(int);
	cout<<peakValue(arr,n);
}