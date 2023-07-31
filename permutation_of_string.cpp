#include <iostream>
#include <string>
using namespace std;

bool checkEqual(int a[26], int b[26])
{
	for (int i = 0; i < 26; i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}

bool checkInclusion(string s1, string s2)
{
	int count1[26] = {0};

	//character count array
	for (int i = 0; i < s1.length(); i++)
	{
		int index = s1[i] - 'a';
		count1[index]++;
	}

	//traverse s2 string in window of size s1.lendth and compare
	int i = 0;
	int count2[26] = {0};
	int windowSize = s1.length();
	while (i < s2.length() && i < windowSize)
	{
		int index = s2[i] - 'a';
		count2[index]++;
		i++;
	}

	if (checkEqual(count1, count2))
		return 1;

	while (i < s2.length())
	{
		char newChar = s2[i];
		int index = newChar - 'a';
		count2[index]++;

		char oldChar = s2[i - windowSize];
		index = oldChar - 'a';
		count2[index]--;
		if (checkEqual(count1, count2))
			return 1;
		i++;
	}

	return false;
}
int main()
{
	string s1 = "ab", s2 = "eidbaoo";
	cout << checkInclusion(s1, s2);
	return 0;
}