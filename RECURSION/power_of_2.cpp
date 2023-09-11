#include <iostream>
using namespace std;

//! TIME COMPLEXITY  --> O(n)
//! SPACE COMPLEXITY --> O(n)
int power(int n)
{
	if (n == 0)
		return 1;

	return 2 * power(n - 1);
}

int main()
{
	int n;
	cout << "Enter power of 2 : ";
	cin >> n;
	cout << "Answer = " << power(n);

	return 0;
}