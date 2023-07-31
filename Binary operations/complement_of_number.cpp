#include <iostream>
using namespace std;

int main()
{
	int n;
	cout<<"Enter a number : ";
	cin >> n;
	int comp_bin = 0;
	int comp_n = 0;
	if (n == 0)
	{
		cout <<"Complement of a number is 1"<<endl;
		goto end;
	}
	for (int i = 0; n != 0; i++)
	{
		int rem = n & 1;
		comp_bin += !rem * pow(10, i);
		n = n >> 1;
	}
	for (int i = 0; comp_bin != 0; i++)
	{
		int rem = comp_bin % 10;
		comp_n += pow(rem, i);
		comp_bin /= 10;
	}
	cout<< "Complement of a number is " << comp_n << endl;
end:
	return 0;
}