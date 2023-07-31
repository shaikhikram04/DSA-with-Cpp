#include <iostream>
#include <string>
using namespace std;

bool checkInclusion(string s1, string s2)
{
	for (int i = 0; i <= s2.length() - s1.length(); i++)
	{
		string window;
		//makeing window of size s1 and check
		for (int j = i; j < i + s1.size(); j++)
			window.push_back(s2[j]);
			
		string temp = s1;
		for (int k = 0; k < window.size(); k++)
		{
			int index = temp.find(window[k]);
			if (window.length())
				temp.erase(temp.begin() + index);
		}
		if (temp.empty())
			return true;
	}

	return false;
}

int main()
{
	string s1 = "ab", s2 = "eidbaoo";
	
	if(checkInclusion(s1,s2))
	cout<<"Permutation of "<<s1<<" is present in the "<<s2<<endl;
	else
	cout<<"Permutation of "<<s1<<" is absent in the "<<s2<<endl;
	
	return 0;
}