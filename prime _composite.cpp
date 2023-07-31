#include <iostream>
using namespace std;

int main()
{
	int num, count = 0;
	cout << "Enter a positive number : ";
	cin >> num;
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			count++;
		}
	}
	
	if (num == 1 || num==0)
		cout << "Number is neither prime nor composite" << endl;

	else if (count > 0)
		cout << "Number is composite" << endl;

	else
		cout << "Number is prime" << endl;
}