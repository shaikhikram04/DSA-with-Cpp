#include <iostream>
using namespace std;

int exponent(int num, int power)
{
	int result = 1;
	while (num != 0)
	{
		//when num is odd
		if (power & 1)
		{
			result = result * num;
		}
		num = num * num;
		power = power >> 1;
	}

	return result;
}

int main()
{
	int p, q;
	cout << "Enter a number : ";
	cin >> p;
	cout << "Enter index of a number : ";
	cin >> q;
	int ans = exponent(p, q);
	cout << "Result = " << ans << endl;
	return 0;
}