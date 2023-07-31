#include <iostream>
#include <string>
using namespace std;

// not perfect 

// TIME COMPLEXITY  --> O(n)
// SPACE COMPLEXITY --> O(n)
bool isPallindrome(string str, int i, int j)
{
	if (i >= j)
		return true;

	if (str[i] != str[j])
		return false;

	else
		isPallindrome(str, i + 1, j - 1);
}

int main()
{
	string str = "bob";
	cout << str << endl;
	if (isPallindrome(str, 0, str.length() - 1))
	{
		cout << "It is a pallindrome" << endl;
	}
	else
	{
		cout << "It is not a pallindrome" << endl;
	}
	return 0;
}