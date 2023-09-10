#include <iostream>
#include <vector>
using namespace std;

bool isSortedAndRotate(vector<int> arr)
{
	int count = 0, n = arr.size();
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			count++;
		if (count > 1)
			return false;
	}
	//* in case arr = {3, 5, 8, 1, 6} -> this is not rotated array
	//* because last element i.e. 6 > 3 (first element) 
	if (arr[n - 1] > arr[0])
		count++;
	
	return count <= 1;
}

int main()
{
	vector<int> arr = {3, 4, 6, 7, 10, 2, 3};
	cout << "Is array is sorted and rotate -> "
		 << isSortedAndRotate(arr) << endl;
	return 0;
}