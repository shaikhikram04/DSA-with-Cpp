#include <iostream>
using namespace std;

int main()
{
	int arr1[] = {1, 3, 5, 7, 9};
	int arr2[] = {2, 4, 6};
	int s1 = sizeof(arr1) / sizeof(int);
	int s2 = sizeof(arr2) / sizeof(int);
	int arr[s1 + s2];
	int i = 0, j = 0, p = 0;

	//* merging
	while (i < s1 && j < s2)
	{
		if (arr1[i] < arr2[j])
			arr[p++] = arr1[i++];
	
		else
			arr[p++] = arr2[j++];

	}	
	while(i < s1) {
		arr[p++]=arr1[i++];
	}	
	while(j < s2) {
		arr[p++]=arr2[j++];
	}


	//* printing
	for (int i : arr)
	{
		cout << i << "  ";
	}
	cout << endl;
	
	return 0;
}