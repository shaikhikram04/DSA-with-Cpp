#include <iostream>
#include <cmath>
using namespace std;

unsigned long long moduloFactorial(int n)
{
	unsigned long long ans = 1;
	unsigned int m = pow(10, 9) + 7;
	for (int i = n; i > 1; i--)
	{
		ans = (ans * i) % m;
		cout <<"ans -> "<< ans << endl;
	}

	return ans;
}

int main()
{
	int n ;
	cin>>n;
	cout << moduloFactorial(n);
	return 0;
}