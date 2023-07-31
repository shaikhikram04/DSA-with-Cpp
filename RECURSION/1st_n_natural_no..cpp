#include <iostream>
using namespace std;

// TIME COMPLEXITY  --> O(n)
// SPACE COMPLEXITY --> O(n)
void print(int n)
{
	if (n == 0)
	{
		return;
	}

	print(n - 1);
	cout << n << endl;
}

int main()
{
	int n;
	cout << "Enter number : ";
	cin >> n;
	cout << "\nSERIES" << endl;
	print(n);

	return 0;
}

