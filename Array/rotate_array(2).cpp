#include <iostream>
#include <vector>
using namespace std;

void rotateArray(vector<int> arr, int s, int k)
{
	vector<int> ansArr(s);
	for (int i = 0; i < s; i++)
	{
		ansArr[(i + k) % s] = arr[i];
	}
	arr = ansArr;
	for (int i = 0; i < s; i++)
		cout << arr[i] << "  ";
	cout << endl;
}

int main()
{
	//*          	   0  1  2  3  4  5
	vector<int> arr = {3, 6, 9, 5, 3, 23};
	int s = arr.size(), k = 2;
	rotateArray(arr, s, k);
	return 0;
}