#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int num ;
	cout <<"Enter a number : ";
	cin>>num;
	int digit_product;
	while (num/10!=0)
	{
		digit_product=1;
		while (num != 0)
		{
			int rem = num % 10;
			digit_product *= rem;
			num = num / 10;
		}
		num = digit_product;
	}
	cout<<num;
	return 0;
}