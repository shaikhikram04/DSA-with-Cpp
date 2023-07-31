#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int num;
	cin >> num;
	int ans = 0;
	if (num < 0)
	{
		cout << "-";
	}
	for (int i = 0; num != 0; i++)
	{
		int bit = num & 1;
		ans = bit * pow(10, i) + ans;
		num /= 2;
	}
	cout << ans << endl;
	return 0;
}