#include <iostream>

using namespace std;

int main()
{
	char ch;
	cout<<"Enter a alpha numeric character"<<endl;
	cin>>ch;
	if(ch>=48 && ch<=57)
	{
		cout<<"You entered numeric character,"<<endl;
	}
	if(ch>=65 && ch<=90){
		cout<<"You entered Uppercase letter"<<endl;
	}
	if(ch>=97 && ch<=122)
	{
		cout<<"You entered lowercase letter"<<endl;
	}
	return 0;
}