#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> arr = {3, 6, 9, 5, 3, 23};
	int k = 2;
	rotate(arr.begin(), arr.begin() + (arr.size() - k), arr.end());
	for (int i : arr)
		cout << i << "  ";
	cout << endl;
	return 0;
}