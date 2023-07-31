#include <iostream>
using namespace std;

int fibonacchi(int n)
{
	if (n == 1)
	{
		return 0;
	}
	if (n == 2)
	{
		return 1;
	}
	int a = 0, b = 1;
	int x;
	for (int i = 3; i <= n; i++)
	{
		x = a + b;
		a = b;
		b = x;
	}
	return x;
}

int main()
{
	int num;
	cin >> num;
	cout << fibonacchi(num);

	return 0;
}