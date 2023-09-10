#include <iostream>
#include <string>
using namespace std;

string removeDuplicate(string s)
{
	int i = 0;
	while (i < s.length())
	{
		int count = 1;
		char ch = s[i];
		
		for (int j = i + 1; j < s.length(); j++)
		{
			if (s[j] == ch)
				count++;
			else
				break;
		}
		
		if (count > 1)
		{
			s.erase(i, count);
			i = 0;
		}
		else
			i++;		
	}

	return s;
}

int main()
{
	string str = "ayxxyz";
	cout<<"Before removing : "<<str<<endl;
	cout<<"After removing : " << removeDuplicate(str)<<endl;
	
	return 0;
}