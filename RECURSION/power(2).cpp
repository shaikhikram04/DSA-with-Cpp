#include <iostream>
using namespace std;

// TIME COMPLEXITY  --> O(n)
// SPACE COMPLEXITY --> O(n)
int power(int m, int n)
{
	if (n == 0)
		return 1;

	if (n == 1)
		return m;

	int ans = power(m, n / 2);

	if (n % 2 == 0)
		return ans * ans;

	else
		return m * ans * ans;
}

int main()
{
	int m, n;
	cin >> m >> n;
	cout<< "Answer = "  << power(m, n) << endl;
	
	return 0;
}