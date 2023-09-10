#include <iostream>
using namespace std;

void duplicate_element(int arr[], int size)
{
	int count;
	for (int i = 0; i < size; i++)
	{
		count=0;
		for (int j = i+1; j < size; j++)
		{
			if (arr[i] == arr[j])
			{
				count++;
			}
		}
		if (count > 0)
		{
			cout << arr[i] << "  ";
		}
	}
	cout << endl;
}

int main()
{
	int arr[]={3,6,8,5,0,4,3,6,7,0};
	int size=sizeof(arr)/sizeof(int);
	duplicate_element(arr,size);
	return 0;
}