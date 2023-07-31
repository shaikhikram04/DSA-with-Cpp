#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cout << "Enter first number  : ";
	cin >> a;
	cout << "Enter second number : ";
	cin >> b;
	int count = 0;
	while (a != 0)
	{
		if ((a & 1) == 1)
		{
			count++;
		}
		a = a >> 1;
	}
	while (b != 0)
	{
		if ((b & 1) == 1)
		{
			count++;
		}
		b = b >> 1;
	}
	cout << "Total number of set bit = " << count;
	return 0;
}