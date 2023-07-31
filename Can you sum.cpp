#include <iostream>
#include <cmath>
using namespace std;

unsigned long long moduloExponential(int x, int n, unsigned long long m)
{
	unsigned long long res = 1;
	while (n != 0)
	{
		//n is odd
		if (n & 1)
		{
			res = (res * (x) % m) % m;
		}
		x = ((x) % m * (x) % m) % m;
		n = n >> 1;
	}
	return res;
}

unsigned long long f(unsigned long long n)
{
	unsigned long long m = pow(10, 9) + 7;
	unsigned long long sum = 0;
	cout << "m-> " << m << endl;
	for (int i = 0; i <= n; i++)
	{
		unsigned long long a = moduloExponential(2, i, m);
		unsigned long long b = (i % m * i % m) % m;
		sum += (a % m * b % m) % m;
		cout << "a->" << a << endl;
		cout << "b->" << b << endl;
		cout << "sum -> " << sum << endl;
	}
	return sum;
}

int main()
{
	unsigned long long n = 420;
	cout << f(n) << endl;

	return 0;
}