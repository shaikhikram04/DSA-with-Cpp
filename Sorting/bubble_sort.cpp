#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> arr = {10, 1, 7, 6, 14, 9};
	int n = arr.size();

	//* bubble sort
	for (int i = 1; i < n; i++)
	{
		bool swaped = false;
		for (int j = 0; j < n - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				swaped = true;
			}
		}
		if (swaped == false)
			break;
	}

	//* printing after sort
	for (int i : arr)
	{
		cout << i << "  ";
	}
	return 0;
}