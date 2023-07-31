#include <iostream>
using namespace std;

bool isprime(int num)
{
	if (num == 1 || num == 0)
		return 0;

	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
			return 0;
	}
	return 1;
}

int main()
{
	int num;
	cout << "Enter a positive number : ";
	cin >> num;
	if (isprime(num))
		cout << endl
			 << num << " is a prime number" << endl;
	else
		cout << endl
			 << num << " is not a prime number" << endl;

	return 0;
}