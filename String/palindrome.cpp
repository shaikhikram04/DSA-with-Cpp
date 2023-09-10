#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str)
{
	int i = 0, j = str.size() - 1;
	while (i < j)
	{
		if (str[i] != str[j])
			return false;
		i++;
		j--;
	}
	return true;
}

int main()
{
	string str = "noon";
	if (isPalindrome(str))
		cout << str << " is a palindrome" << endl;
	else
		cout << str << " is not a palindrome" << endl;
	return 0;
}