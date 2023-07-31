#include <iostream>
#include <string>
using namespace std;

string replaceSpace(string str)
{
	string ansStr;
	for (int i = 0; i < str.size(); i++)
	{
		if (str.at(i) == ' '){
			ansStr+="@40";
		}
		else
			ansStr.push_back(str[i]);
	}
	str=ansStr;
	return str;
}

int main()
{
	//string str = "Coding Ninjas is coding platform";
	string str="Hello World";
	cout<<replaceSpace(str)<<endl;
	return 0;
}