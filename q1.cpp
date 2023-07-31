#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float height;
	float bounce;
	float window;
	cout << "Height of the building : ";
	cin >> height;
	cout << "Bouncing : ";
	cin >> bounce;
	cout << "Height of the window from the ground : ";
	cin >> window;
	int count = 1;
	float seen;
	if (bounce > 0 && bounce < 1)
	{
		for (;;)
		{
			seen = height * bounce;
			height = seen;
			if (height > window)
			{
				count += 2;
			}

			else
			{
				break;
			}
		}
		cout << count;
	}
	else
	{
		cout << "-1";
	}
	return 0;
}