#include <iostream>
using namespace std;

int climbStairs(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    int a = 1, b = 2;
    int count;
    for (int i = 3; i <= n; i++)
    {
        count = a + b;
        a = b;
        b = count;
    }
    return count;
}

int main()
{
	int n;
	cout << "Enter no. of stairs : ";
	cin >> n;
	cout << "No. of distinct way of climb stair = " << climbStairs(n) << endl;

	return 0;
}

