#include <iostream>
using namespace std;

int main()
{
	//Difference between product and sum of the digit of a number
	int num,sum,product,rem;
	cout<<"Enter a number : ";
	cin>>num;
	sum=0;
	product=1;
	while(num!=0){
		rem=num%10;
		sum+=rem;
		product*=rem;
		num=num/10;
		//cout<<sum<<"\t"<<product<<endl;
	}
	int difference=product-sum;
	cout<<"Difference = "<<difference;
	return 0;
}