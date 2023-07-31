#include <iostream>
#include <string>
#include <vector>
using namespace std;

string reverseWord(string str)
{
	string ans;
	int start = 0, j, s = str.size();

	for (int i = 0; i < s; i++)
	{
		if (str[i] == ' ' || i == s - 1)
		{
			if (i == s - 1)
				j = s - 1;
			else
				j = i - 1;
			while (j >= start)
			{
				ans.push_back(str[j]);
				j--;
			}
			if (str[i] != s - 1)
				ans.push_back(' ');
			start = i + 1;
		}
	}
	return ans;
}

int main()
{
	string str = "My name is Ikram";
	cout << reverseWord(str);
	return 0;
}