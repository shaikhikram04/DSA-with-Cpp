#include <iostream>
using namespace std;

int main()
{
	int arr[]={1,2,3,4,3};
	int size=sizeof(arr)/sizeof(int);
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++){
			if(j==i) continue;
			if(arr[i]==arr[j]){
				cout<<arr[i];
				//return 0;
				exit(0);
			}
		}
	}
	return 0;
}