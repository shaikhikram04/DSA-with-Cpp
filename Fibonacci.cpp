#include <iostream>
using namespace std;

int main()
{
	int n=10;
	int a=0,b=1,c;
	cout<<a<<" "<<b<<" ";
	for(int i=1;i<=n;i++)
	{
		c=a+b;
		cout<<c<<" ";
		a=b;
		b=c;
	}
	cout<<endl;
	
	return 0;
}