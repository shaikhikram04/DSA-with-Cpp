#include <iostream>
using namespace std;

int main()
{
	int secin, hours, minutes, second;
	cout << "Enter seconds : ";
	cin >> secin;
	hours = secin / 3600;
	int remain = secin % 3600;
	minutes = remain / 60;
	remain = remain % 60;
	second = remain;
	cout << "Hours = " << hours << endl
		 << "Minutes = " << minutes << endl
		 << "Second = " << second;
	return 0;
}