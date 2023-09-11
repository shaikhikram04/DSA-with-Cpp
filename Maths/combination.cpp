#include <iostream>
using namespace std;

int factorial(int num)
{
	int ans = 1;
	for (int i = 1; i <= num; i++)
	{
		ans *= i;
	}
	return ans;
}

int nCr(int n, int r)
{
	int ans = factorial(n) / (factorial(r) * factorial(n - r));
	return ans;
}

int main()
{
	int answer = nCr(8,2);
	cout << answer;
	return 0;
}