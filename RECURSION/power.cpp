#include <iostream>
using namespace std;

// TIME COMPLEXITY  --> O(n)
// SPACE COMPLEXITY --> O(n)
int power(int m, int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return m * power(m, n - 1);
	}
}

int main()
{
	int m, n;
	cin >> m >> n;
	cout << power(m, n) << endl;
	return 0;
}