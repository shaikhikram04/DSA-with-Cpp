#include <iostream>
#include <cmath>
using namespace std;

float func(float x);
int main()
{
	float a, b, x, func_a, func_b, func_x;
	a = 0;
	b = 1;

	for (int i = 1; i <= 4; i++)
	{
		func_a = func(a);
		func_b = func(b);
		x = b - ((b - a) * func_b) / (func_b - func_a);
		func_x = func(x);
		cout << "Iteration " << i << " : " << x << "\t" << func_x << endl;
		a = b;
		b = x;
		if (abs(func_x) < 0.001)
		{
			break;
		}
	}
	return 0;
}

float func(float x)
{
	float myfunction = pow(x, 3) - 5.0 * x + 1.0;
	return myfunction;
}