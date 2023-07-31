#include <iostream>
using namespace std;

void update(int **ptr)
{
//	ptr = ptr +1;
	// kuch change hua -> NO
	
//	*ptr=*ptr+1;
	//kuch change hua -> YES
	
	**ptr=**ptr+1;
	//kuch change hua -> YES
}


int main()
{
	int i=5;
	int *p1=&i;
	int **p2=&p1;
	
	cout<<"Printing value of i "<<endl;
	cout<<i<<endl;
	cout<<*p1<<endl;
	cout<<**p2<<endl;
	
	cout<<endl<<"Printing address of i"<<endl;
	cout<<&i<<endl;
	cout<<p1<<endl;
	cout<<*p2<<endl;
	
	cout<<endl<<"Printing address of p1"<<endl;
	cout<<&p1<<endl;
	cout<<p2<<endl;
	
	cout<<endl;
	cout<<"Before update : "<<endl;
	cout<<"i -> "<<i<<endl;
	cout<<"p1 -> "<<p1<<endl;
	cout<<"p2 -> "<<p2<<endl;
	
	update(p2);
	cout<<"\nAfter update : "<<endl;
	cout<<"i -> "<<i<<endl;
	cout<<"p1 -> "<<p1<<endl;
	cout<<"p2 -> "<<p2<<endl;
	
	
	return 0;
}