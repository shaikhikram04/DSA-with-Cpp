#include <iostream>
#include <string>
using namespace std;

void reverseWord(string s)
{
	string ans;
	int last = s.size() - 1, j;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] == ' ' || i == 0)
		{
			if (i == 0)
				j = 0;
			else
				j = i + 1;
			while (j <= last)
			{
				ans.push_back(s.at(j));
				j++;
			}
			if (i != 0)
				ans.push_back(s.at(i));
			last = i - 1;
		}
	}
	cout << ans;
}

int main()
{
	//vector<char> v = {'T', 'h', 'e', ' ', 'S', 'k', 'y', ' ', 'i', 's', ' ', 'b', 'l', 'u', 'e'};
	string str="My name is Ikram";
	reverseWord(str);

	return 0;
}