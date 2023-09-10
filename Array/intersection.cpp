#include <iostream>
using namespace std;

void intersection(int arr1[], int size1, int arr2[], int size2)
{
	
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (arr1[i] == arr2[j])
			{
				cout << arr1[i] << "  ";
				arr2[j]=-87392;
				break;
			}
		}
	}
	cout << endl;
}

int main()
{
	int arr1[] = {1, 6, 8, 4,1, 3, 0};
	int arr2[] = {8 ,1,5, 9, 3};
	int size1 = sizeof(arr1) / sizeof(int);
	int size2 = sizeof(arr2) / sizeof(int);

	intersection(arr1, size1, arr2, size2);
	
	return 0;
}