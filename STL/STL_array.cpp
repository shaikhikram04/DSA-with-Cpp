#include <iostream>
#include <array>
using namespace std;
int main()
{
	//initializing an intezer array of name arr and of size 4
	array<int,4> arr={1,2,3,4};
	
	//size of an array
	int size =arr.size();
	
	//printing an array
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<endl;
	}
	
	cout<<"Element of second index : "<<arr.at(2)<<endl;
	
	//return a boolen value that represent array is empty or not
	cout<<"array empty or not ->"<<arr.empty()<<endl;
	
	cout<<"first element ->"<<arr.front()<<endl;
	cout<<"Last element ->"<<arr.back()<<endl;
	return 0;
}