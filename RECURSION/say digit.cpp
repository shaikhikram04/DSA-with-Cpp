#include <iostream>
using namespace std;

// TIME COMPLEXITY  --> O(n)
// SPACE COMPLEXITY --> O(n)
void say_digit(int n)
{
	string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

	if (n == 0)
		return;

	int rem = n % 10;
	say_digit(n / 10);
	cout << arr[rem] << " ";
}

int main()
{
	int n;
	cin >> n;

	say_digit(n);

	return 0;
}