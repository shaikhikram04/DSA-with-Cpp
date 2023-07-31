#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int num;
	cout << "Enter a decimal number : ";
	cin >> num;
	int maxIndex;
	for (int i = 0;; i++)
	{
		if (pow(2, i) > num)
		{
			maxIndex = i;
			break;
		}
	}
	int binary[maxIndex];
	for (int i = maxIndex - 1; i >= 0; i--)
	{
		int rem = num % 2;
		binary[i] = rem;
		num /= 2;
	}
	cout << "\nBinary form of number is ";
	for (int i = 0; i < maxIndex; i++)
	{
		cout << binary[i];
	}
	cout << endl;
	return 0;
}