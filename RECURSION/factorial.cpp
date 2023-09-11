#include <iostream>
using namespace std;

//! TIME COMPLEXITY  --> O(n)
//! SPACE COMPLEXITY --> O(n)
int factorial(int num)
{
	//* base condition
	if (num == 0)
		return 1;
		
	//* recursive relation
	return num * factorial(num - 1);
}

int main()
{
	int num;
	cout << "Ener a number : ";
	cin >> num;

	int ans = factorial(num);

	cout << "Factorial = " << ans;
	return 0;
}