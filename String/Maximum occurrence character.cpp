#include <iostream>
#include <string>
using namespace std;

char maxOccChar(string str)
{
	char arr[26] = {0};

	//create an array of count of character
	for (int i = 0; i < str.size(); i++)
	{
		int ch = str[i];
		int number = ch - 'a';
		arr[number]++;
	}

	//find maximum occ character
	int ans, maxi = -1;
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] > maxi)
		{
			ans = i;
			maxi = arr[i];
		}
	}
	char finalAns = ans + 'a';
	return finalAns;
}

int main()
{
	string str = "test";
	cout << "Maximum occurance characrr -> " << maxOccChar(str)<<endl;
	return 0;
}