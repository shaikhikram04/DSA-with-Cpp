#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int root = 0;
	while (!(root > 0 && root < 10))
	{
		root = 0;
		while (n != 0)
		{
			root += n % 10;
			n /= 10;
		}
		n = root;
	}
	cout << root << endl;
	return 0;
}