#include <iostream>
using namespace std;

int main()
{
	int arr[12] = {52, 2, 8, 21, 9, 35};

	// printing first element address of array
	cout << "address of arr -> " << arr << endl;

	cout << "address of first memory block -> " << &arr[0] << endl;
	cout << "value of first memory block -> " << arr[0] << endl;
	cout << "value of first memory block -> " << *arr << endl;
	//printing arr[0]+1
	cout << "5th -> " << (*arr) + 1 << endl;
	//printing 4th element of array
	cout << "6th -> " << arr[3] << endl;
	cout << "7th -> " << *(arr + 3) << endl;

	int temp[10];
	cout << sizeof(temp) << endl;

	int *p = &temp[0];
	cout << sizeof(p) << endl;
	cout << sizeof(*p) << endl;
	
	//ERROR
	//address of array cannot be reassign
	//arr=arr+1;
	
	return 0;
}