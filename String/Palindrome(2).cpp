#include <iostream>
#include <string>
using namespace std;

// Only check for number and letters
//Also it is not case sencetive
bool isPalindrome(string str)
{
	string s;
	for (int i = 0; i < str.size(); i++)
	{
		if (!((str[i] >= '0' && str[i] <= '9') || (str[i] > 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')))
			continue;
		if (str[i] > 'A' && str[i] <= 'Z')
			str[i] = str[i] - 'A' + 'a';
		s.push_back(str[i]);
	}
	int i = 0, j = s.size() - 1;
	while (i < j)
	{
		if (s[i] != s[j])
			return false;
		i++;
		j--;
	}
	return true;
}

int main()
{
	string str = "pty54&64+5y(T#P";
	if (isPalindrome(str))
		cout << str << " is palindrome" << endl;
	else
		cout << str << " is not palindrome" << endl;
	return 0;
}