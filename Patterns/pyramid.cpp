#include <iostream>
#include <string>

using namespace std;

int main()  
{
	int n;
	cout<<"Enter a number : ";
	cin>>n;
	cout<<endl;
	for(int i=1;i<=n;i++){
		for(int s=n-i;s>=1;s--){
			cout<<"  ";
		}
		for(int a=1;a<=2*i-1;a++){
			cout<<"* ";
		}
		cout<<endl;
	}
	return 0;
}