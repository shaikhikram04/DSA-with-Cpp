#include <iostream>
using namespace std;

int gdp(int a, int b)
{
	if (a == 0)
		return b;

	else if (b == 0)
		return a;

	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}

int main()
{
	int a, b;
	cout << "FIND GDP" << endl<<endl;
	cout << "Enter first number : ";
	cin >> a;
	cout << "Enter second number : ";
	cin >> b;
	int ans = gdp(a, b);
	cout << "GDP of " << a << " and " << b << " is " << ans << endl;

	return 0;
}