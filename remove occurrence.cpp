#include <iostream>
#include <string>
using namespace std;

string removeOccurrance(string s, string part)
{
	string temp;
	while (s.find(part) < s.size())
	{
		int index = s.find(part);
		for (int j = index; j < index + part.size(); j++)
			temp.push_back(s[j]);
		if (temp == part)
			s.erase(s.begin() + index, s.begin() + index + 3);
		temp.clear();
	}

	return s;
}

int main()
{
	string s = "daabcbaabcbc";
	string part = "abc";
	cout << removeOccurrance(s, part) << endl;
	return 0;
}