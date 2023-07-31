#include <iostream>
#include <vector>
using namespace std;

int countPrime(int num)
{
	int cnt = 0;
	vector<bool> prime(num + 1, true);

	//	prime[0] = prime[1] = 0;

	for (int i = 2; i < num; i++)
	{
		if (prime[i])
		{
			cnt++;

			for (int j = 2 * i; j < num; j += i)
			{
				prime[j] = 0;
			}
		}
	}

	return cnt;
}

int main()
{
	int num;
	cout << "Enter a number : ";
	cin >> num;
	cout << "Number of prime number from 2 to " << num << " : " << countPrime(num) << endl;

	return 0;
}