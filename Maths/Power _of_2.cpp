#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int num;
	cin >> num;
	float ans = log2(num);
	if (ans == (int)(ans))
	{
		cout << "true";
	}
	else
	{
		cout << "False";
	}

	return 0;
}