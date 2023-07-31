#include <iostream>
using namespace std;

bool isPrime(int num)
{
	for(int i=2;i<num;i++)
	{
		if(num%i==0)
		return 0;
	}
	return 1;
}

int countPrime(int num)
{
	int count = 0;
	for (int i = 2; i < num; i++)
	{
		if (isPrime(i))
			count++;
	}

	return count;
}

int main()
{
	int num;
	cout << "Enter a number : ";
	cin >> num;
	cout << "Number of prime number from 2 to " << num << " : " << countPrime(num) << endl;
	return 0;
}