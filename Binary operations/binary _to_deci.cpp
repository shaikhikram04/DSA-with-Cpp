#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int bin_num;
	cout << "Enter a binary number : ";
	cin >> bin_num;
	int deci_num = 0;
	for (int i = 0; bin_num != 0; i++)
	{
		
		int rem = bin_num % 10;
		if(rem>1)
		{
			cout<<"Please enter binary number"<<endl;
			goto end;
		}
		deci_num += rem * pow(2, i);
		bin_num /= 10;
	}
	cout << "\nDecimal form of the number is " << deci_num << endl;
end:
	return 0;
}