#include <iostream>
using namespace std;

void rotateArray(int arr[], int s, int k)
{
	int ansArr[s];
	for (int i = 0; i < s; i++)
	{
		if (i - k >= 0)
			ansArr[i] = arr[i - k];
		else
		   ansArr[i]=arr[i+s-k];
		   
		cout<<ansArr[i]<<"  ";
	}
}

int main()
{
	int arr[] = {3, 6, 9, 5, 3, 23};
	int s = sizeof(arr) / sizeof(int), k = 2;
	rotateArray(arr, s, k);
	return 0;
}