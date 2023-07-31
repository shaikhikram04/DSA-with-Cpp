#include <iostream>
using namespace std;

int main()
{
	//referenced variable
	int a = 5;
	int &b = a;
	b++;
	cout << " a -> " << a << endl;
	cout << " b -> " << b << endl;
	cout << &a << endl;
	cout << &b << endl;

//	int *p = &a;
//	cout << "address of a -> " << p << endl;
//	cout << "value of a -> " << *p << endl;

	// If we only define pointer then it takes address of any garbage value
	// so, initialize it with 0
	int *q = 0;
	int i = 3;
	q = &i;
	cout << "value of i -> " << *q << endl;
	
	//copying a pointer
	double c = 76;
	double *ptr = &c;
	double *cptr = ptr;
	cout << ptr << " -- " << cptr << endl;
	cout << *ptr << " -- " << *cptr << endl;
	ptr++;
	cout<<"after inc address by 1 -> "<<ptr<<endl;
	ptr+=2;
	cout<<"after inc address by 1 -> "<<ptr<<endl;
	
	float f=10.5;
	float p=2.5;
	float* fptr=&f;
	(*fptr)++;
	*fptr=p;
	cout<<*fptr<<" "<<f<<" "<<p<<endl;
	
	return 0;
}