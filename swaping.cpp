#include <iostream>
#include <string>

using namespace std;

void swap(int &a,int &b);
int main()
{
	int fnum=10;
	int snum=20;
	
	cout<<"Before swap\n";
	cout<<fnum<<"\t"<<snum<<"\n";
	
	swap(fnum,snum);
	cout<<"After swap\n";
	cout<<fnum<<"\t"<<snum;
	return 0;
}

void swap(int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
}