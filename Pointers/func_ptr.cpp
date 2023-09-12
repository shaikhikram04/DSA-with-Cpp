#include <iostream>
using namespace std;

//*  here pass by value is happen
void update(int *ptr)
{
	*ptr = *ptr + 1;
}

int get_sum(int arr[], int s)
{
	int sum = 0;
	//*  it print size of a pointer that point first element of arr
	cout << "\nsize -> " << sizeof(arr) << endl;
	for (int i = 0; i < s; i++)
	{
		sum += arr[i];
	}

	return sum;
}

int* fun(int n) {
    int* ptr = &n;
    return ptr;
}

int main()
{
	int n = 4;
	int *ptr = &n;
	cout << "before update : " << *ptr << endl;
	update(ptr);
	cout << "After update : " << *ptr << endl;

	int arr[5] = {1, 2, 3, 4, 5};

	//* NOTE : When we pass array in a function then it not pass whole array as argument it pass pointer that point first element of an array
	cout << get_sum(arr, 5) << endl;

	 n = 5;

    cout << fun(n);
	
	return 0;
}