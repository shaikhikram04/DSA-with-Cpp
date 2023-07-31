#include <iostream>
using namespace std;

int main()
{
	int n;
	cout<<"Enter a number : ";
	cin>>n;
	cout<<endl;
	for (int i = n; i >= 1; i--)
	{
		for (int f = 1; f <= i; f++)
		{
			cout << f << " ";
		}
		for (int a = 0; a < n - i; a++)
		{
			cout << "* * ";
		}
		for (int e = i; e >= 1; e--)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	return 0;
}