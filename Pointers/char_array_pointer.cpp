#include <iostream>
using namespace std;

int main()
{
	int arr[5] = {1, 2, 3, 4, 5};

	//* size of character array is 1 more than no of element in the arr because it contain null character
	char ch[6] = "abcde";

	//* printing int arr address
	cout << arr << endl;
	//* printing char arr
	cout << ch << endl;

	char *ptr = &ch[0];
	//* it print value of address location assined by ptr and it continuous printing value of next location address until it got null character
	cout << ptr << endl;

	char temp = 'p';
	char *p = &temp;
	cout << p << endl;
	
	
	
	return 0;
}