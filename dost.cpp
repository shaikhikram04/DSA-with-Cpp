#include <iostream>
#include <cmath>
using namespace std;

double NP_Squrt(int num, int p)
{
	int start = 0;
	int end = num / 2 + 1;
	double ans;
	while (start <= end)
	{
		ans = (start + end) / 2;
		if (ans * ans == num)
			break;

		if (num > ans * ans && num < (ans + 1) * (ans + 1))
			break;

		if (ans * ans > num)
			end = ans - 1;

		else
			start = ans + 1;
	}

	double i = 0.1;
	double a;
	for (;;)
	{
		if(i==0.1/pow(10,p))
			break;

		a = ans + i;
		if (a * a == num)
			break;

		if (a * a < num)
			ans = a;

		if (a * a > num)
			i = i / 10;
	}

	return ans;
}

int main()
{
	while (1)
	{
		int num;
		cout << "Enter a positive number : ";
		cin >> num;
		cout << "Square root of " << num << " is " << NP_Squrt(num, 6) << endl
			 << endl;
	}
	return 0;
}