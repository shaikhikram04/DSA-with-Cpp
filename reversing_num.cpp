#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int num;
	int rew = 0;
	cin >> num;

	while (num != 0)
	{
		int rem = num % 10;
		rew = rew * 10 + rem;
		num /= 10;
	}
	cout << rew;
	return 0;
}