#include <iostream>
#include <string>
using namespace std;

string replaceSpace(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str.at(i) == ' ')
		{
			str.resize(str.size() + 2);
			for (int j = str.size()-1; j >= i+1; j--)
			{
				str[j]=str[j-2];
			}
			str[i] = '@';
			str[i + 1] = '4';
			str[i + 2] = '0';
			i += 2;
		}
		else
		{
			continue;
		}
	}
	return str;
}

int main()
{
	string str = "Coding Ninjas is coding platform";
	//string str = "Hello World";
	cout << replaceSpace(str) << endl;
	return 0;
}