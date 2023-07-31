#include <iostream>
#include <cmath>

using namespace std;

float eqn; //global variable
float func(float x);
void equation(int deg, float coef[], float var[]);
int main()
{
	float a = -1, b = -2, funca, funcb, funcx, x;
	int nOl, degree;
	cout << "Enter degree of equation : ";
	cin >> degree;
	float coefficient[degree + 1];
	float variable[degree + 1];
	for (int c = degree; c >= 0; c--)
	{
		cout << "Enter coefficient of variable of index " << c << " :";
		cin >> coefficient[c];
	}
	for (int i = degree; i >= 0; i--)
	{
		variable[i] = pow(x, i);
	}
	eqn = 0;
	for (int e = degree; e >= 0; e--)
	{
		eqn += (coefficient[e] * variable[e]); //adding term to make equation
	}
	//equation(degree, coefficient, variable);

	funca = func(a);	   //f(a)
	funcb = func(b);	   //f(b)
	cout << funca << endl; //for testing
	cout << funcb << endl; //for testing
	cout << "Enter no. of Iteration : ";
	cin >> nOl;
	for (int i = 1; i <= nOl; i++)
	{
		x = (a + b) / 2;
		funcx = func(x); //f(x)
		if (funcx == 0)
		{
			cout << x << " is the root of the equation";
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
		cout << "Iteration " << i << ":\t" << a << "\t\t" << b << endl;
	}

	return 0;
}
void equation(int deg, float coef[], float var[])
{
	eqn = 0;
	for (int i = deg; i >= 0; i--)
	{
		eqn += (coef[i] * var[i]); //adding term to make equation
	}
}

float func(float x)
{
	float myfunction = eqn; //storing equation that already made
	return myfunction;
}