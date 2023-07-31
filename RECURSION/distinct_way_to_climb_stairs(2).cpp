#include <iostream>
using namespace std;

// TIME COMPLEXITY  --> O(2^n)
// SPACE COMPLEXITY --> O(n)
int count(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;

	return count(n - 1) + count(n - 2);
}

int main()
{
	int n;
	cout << "Enter no. of stairs : ";
	cin >> n;
	cout << "No. of distinct way of climb stair = " << count(n) << endl;

	return 0;
}