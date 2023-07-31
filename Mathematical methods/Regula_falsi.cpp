#include <iostream>
#include <cmath>
using namespace std;

float func(float x);
int main()
{
	float a, b, x, funca, funcb, funcx;
	a = 1;
	b = 2;
	for (int i = 1;; i++)
	{
		funca = func(a);
		funcb = func(b);
		x = b - (((b - a) * funcb) / (funcb - funca));
		funcx = func(x);
		if (abs(funcx)< 0.001)
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

		cout << "Iteration " << i << " : " << a << "\t" << b << endl;
	}
	return 0;
}

float func(float x)
{
	float myfunction = pow(x, 3) - x - 4.0;
	return myfunction;
}