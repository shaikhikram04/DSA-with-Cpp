#include <iostream>
using namespace std;
unsigned long long rowSumOddNumbers(int n)
{
	long long num = (n * n) - (n - 1);
	long long ans=0;
	for (int i = 1; i <= n; i++)
	{
		ans+=num;
		num+=2;
	}
	return ans;
}

int main()
{
	cout << rowSumOddNumbers(42);
	return 0;
}