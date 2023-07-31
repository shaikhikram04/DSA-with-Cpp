#include <iostream>
#include <cmath>

using namespace std;

float func(float x);
int main()
{
	float a, b, funca, funcb, funcx, x;
	a = 1;
	b = 2;
	funca = func(a); //f(a)
	funcb = func(b); //f(b)
	for (int i = 1;; i++)
	{
		x = (a + b) / 2;
		funcx = func(x); //f(x)
		if (abs(funcx) < 0.001)
		{
			cout << "Iteration " << i << ": ";
			cout << "\nRoot of the equation is " << x << endl;
			break;
		}
		else if (funcx < 0)
		{
			a = x;
		}
		else
		{
			b = x;
		}
		cout << "Iteration " << i << ":\t" << a << "\t" << b << endl;
	}
	return 0;
}

float func(float x)
{
	float myfunction = pow(x,2) - 3;
	return myfunction;
}