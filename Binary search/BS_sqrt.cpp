#include <iostream>
#include <cmath>
using namespace std;

int square_root(int num)
{
	int start = 0;
	int end = num / 2 + 1;
	int ans;
	while (1)
	{
		ans = (start + end) / 2;
		if (pow(ans, 2) == num)
			return ans;

		if (num > pow(ans, 2) && num < pow(ans + 1, 2))
			return ans;

		if (pow(ans, 2) > num)
			end = ans - 1;

		else
			start = ans + 1;
	}
	return -1;
}

int main()
{
	while (1)
	{
		int num;
		cout << "Enter a positive number : ";
		cin >> num;
		cout << "Square root of " << num << " is " << square_root(num) << endl
			 << endl;
	}
	return 0;
}