#include <iostream>
#include <string>
using namespace std;

// TIME COMPLEXITY  --> O(n)
// SPACE COMPLEXITY --> O(n)
string reverseString(string str, int i)
{
	int j = str.size() - 1 - i;
	if (i >= j)
	{
		return str;
	}
	else
	{
		swap(str[i], str[j]);
		return reverseString(str, i + 1);
	}
}

int main()
{
	string str = "Maarki";
	cout << "Reversed string --> " << reverseString(str, 0);
	return 0;
}