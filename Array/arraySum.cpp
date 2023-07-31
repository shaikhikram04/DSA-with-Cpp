#include <iostream>
using namespace std;

int sumOfArray(int arr[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
}

int main()
{
	int arr[6]={4,6,3,1,9,7};
	int sum=sumOfArray(arr,6);
	cout<<"Sum = "<<sum;
	return 0;
}