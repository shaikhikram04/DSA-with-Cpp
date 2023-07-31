#include <iostream>
using namespace std;

int moduloExponential(int x, int n, int m)
{
	int res = 1;
	while (n != 0)
	{
		//n is odd
		if (n & 1)
		{
			res = ( res * (x) % m) % m;
		}
		x = ((x) % m * (x) % m) % m;
		n = n >> 1;
	}
	return res;
}

int main()
{
	int x=2;
	int n=7;
	int m=3;
	
	int ans = moduloExponential(x,n,m);
	cout<<"Modulo exponential = "<<ans<<endl;
	return 0;
}