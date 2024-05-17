#include <iostream>
#include <array>
#include <string>
using namespace std;

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i];
	}
}

int no_of_zero(int arr[], int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 0)
			count++;
	}
	return count;
}

void sort0_1_2(int arr[], int n)
{
	int left, right, middle;
	left = 0;
	right=n-1;
	int m=no_of_zero(arr, n);
	middle = m;
	while (left < m ){
		if(arr[left]==0 ) left++;
		if(arr[middle]==1 && middle<2*m) middle++;
		if(arr[right]==2 && right>=2*m) right--;
		if(arr[left]==1 && arr[middle]==0 && middle<2*m){
			swap(arr[left],arr[middle]);
			left--;
			middle++;
		}
		if(arr[right]==1 && arr[middle]==2 && middle<2*m && right>=2*m){
			swap(arr[right],arr[middle]);
			right++;
			left--;
		}
		if(arr[left]==2 && arr[right]==0 && right>=2*m ){
			swap(arr[left],arr[right]);
		}
	}
	printArray(arr,n);
}
int main()
{
	int arr[] = {0, 2, 2, 1, 0, 2, 1, 0, 1, 0, 2, 1};
	int n= sizeof(arr) / sizeof(int);
	sort0_1_2(arr,n);
	printArray(arr,n);
	return 0;
}