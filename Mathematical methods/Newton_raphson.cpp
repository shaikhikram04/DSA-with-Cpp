#include <iostream>
#include <cmath>
using namespace std;

float func(float x);
float D_func(float x);
int main()
{
	float a = 1, b = 2, x, x1;
	float funca = func(a);
	float funcb = func(b);
	if (abs(funca) < abs(funcb))
	{
		x = a;
	}
	else
	{
		x = b;
	}
	for (int i = 1;; i++)
	{
		float funcx = func(x);
		float dfuncx = D_func(x);
		x1 = x - (funcx / dfuncx);
		float funcx1 = func(x1);
		if (abs(funcx) < 0.001)
		{
			cout << "\nIteration " << i << " : ";
			cout << "\nRoot of the equation is " << x << endl;
			break;
		}
		cout << "Iteration " << i << " : " << x1 << "\t" << funcx1 << endl;

		x = x1;
	}
	return 0;
}

float func(float x)
{
	float myfunction = pow(x, 4) - x - 10;
	return myfunction;
}

float D_func(float x)
{
	float myDfunction = 4 * pow(x, 3) - 1;
	return myDfunction;
}