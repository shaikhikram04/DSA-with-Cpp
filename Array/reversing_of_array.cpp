// problem link : https://practice.geeksforgeeks.org/problems/reverse-a-string/1

#include <iostream>
using namespace std;

void printarray(int arr[],int size)
{
	for(int i=0;i<size;i++){
		cout<<arr[i]<<"  ";
	}
}

void reverse_array(int arr[], int size)
{
	for (int i = 0; i < (size / 2); i++)
	{
		//swap
		swap(arr[i], arr[size - i - 1]);
	}
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 8};
	int size = sizeof(arr) / sizeof(int);
	printarray(arr,size);
	reverse_array(arr,size);
	cout<<endl;
	printarray(arr,size);
	return 0;
}