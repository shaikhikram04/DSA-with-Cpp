#include <iostream>
using namespace std;

int main()
{
	int note100;
	int note50;
	int note20;
	int note1;
	int amount;

	cout << "Enter an amount : ";
	cin >> amount;
	note100 = amount / 100;
	int remaining = amount % 100;
	note50 = remaining / 50;
	remaining %= 50;
	note20 = remaining / 20;
	remaining %= 20;
	note1 = remaining;
	cout << "Number of 100's' note is " << note100 << endl;
	cout << "Number of 50's note is " << note50 << endl;
	cout << "Number of 20's note is " << note20 << endl;
	cout << "Number of 1's note is " << note1 << endl;

	return 0;
}