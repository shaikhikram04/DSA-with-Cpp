#include <iostream>
using namespace std;

//! TIME COMPLEXITY  --> O(2^n)
//! SPACE COMPLEXITY --> O(n)
int fibonacchi(int n)
{
	if (n == 0)
		return 0;

	else if (n == 1)
		return 1;
		
	return fibonacchi(n - 1) + fibonacchi(n - 2);
}

int main()
{
	int n;
	cout << "Enter number : ";
	cin >> n;
	cout << "fibonacci no. at " << n << " is -> " << fibonacchi(n);

	return 0;
}