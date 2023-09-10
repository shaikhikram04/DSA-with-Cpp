#include <iostream>
#include <string>
using namespace std;
string createPhoneNumber(int arr[])
{
	string phNumber;
	int j = 0;
	for (int i = 0; i < 14; i++)
	{
		if (i == 0)
		{
			phNumber.push_back('(');
			continue;
		}
		else if (i == 4)
		{
			phNumber.push_back(')');
			continue;
		}
		else if (i == 5)
		{
			phNumber.push_back(' ');
			continue;
		}
		else if (i == 9)
		{
			phNumber.push_back('-');
			continue;
		}
		phNumber.push_back(arr[j]+48);
		j++;
	}
	return phNumber;
}
int main()
{
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	cout<<createPhoneNumber(arr);
	return 0;
}
