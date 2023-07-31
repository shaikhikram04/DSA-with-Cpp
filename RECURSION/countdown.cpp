#include <iostream>
using namespace std;

// TIME COMPLEXITY  --> O(n)
// SPACE COMPLEXITY --> O(n)
void count_down(int n)
{
	if (n == 0){
		return;
	}
	cout << n << endl;
	count_down(n - 1);
}

int main()
{
	int n;
	cout << "Enter number : ";
	cin >> n;
	cout << "\nCOUNTDOWN" << endl;
	count_down(n);
	
	return 0;
}