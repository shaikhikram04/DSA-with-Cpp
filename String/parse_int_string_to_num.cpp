#include <string>
#include <vector>
#include <iostream>
using namespace std;
long parse_int(string number)
{
	int ans = 0;
	int num = 0;
	int i = 0, j;
	string tempstr;
	while (i < number.size())
	{
		vector<char> word;
		for (j = i; j < number.size(); j++)
		{
			if (number[j] == ' ' || number[j] == '-')
				break;
			word.push_back(number[j]);
		}
		string str(word.begin(), word.end());
		int s = str.size();
		int n = 0;
		if (str == "zero")
			n += 0;
		else if (str == "one")
			n += 1;
		else if (str == "ten")
			n += 10;
		else if (str == "eleven")
			n += 11;
		else if (str == "twelve")
			n += 12;
		else if (str == "hundred")
		{
			if (num == 0)
				num = 1;
			num *= 100;
		}
		else if (str == "thousand")
		{
			if (num == 0)
				num = 1;
			num *= 1000;
		}
		else if (str == "million")
		{
			if (num == 0)
				num = 1;
			num *= 1000000;
		}
		else if (str[0] == 't' && str[1] == 'w')
			n += 2;
		else if (str[0] == 't' && str[1] == 'h')
			n += 3;
		else if (str[0] == 'f' && str[1] == 'o')
			n += 4;
		else if (str[0] == 'f' && str[1] == 'i')
			n += 5;
		else if (str[0] == 's' && str[1] == 'i')
			n += 6;
		else if (str[0] == 's' && str[1] == 'e')
			n += 7;
		else if (str[0] == 'e' && str[1] == 'i')
			n += 8;
		else if (str[0] == 'n' && str[1] == 'i')
			n += 9;

		if (str[s - 3] == 'e' && str[s - 2] == 'e' && str[s - 1] == 'n')
			n += 10;
		else if (str[s - 2] == 't' && str[s - 1] == 'y')
			n *= 10;

		num += n;
		if (str == "hundred" || str == "thousand" || str == "million")
		{
			if (tempstr == "hundred" || tempstr == "thousand" || tempstr == "million")
			{
				ans *= 1000;
				num = 0;
			}
			else if (ans > num || ans == 0)
			{
				ans += num;
				num = 0;
			}
			else
			{
				if (str == "hundred")
					ans = ans * 100 + num;
				if (str == "thousand")
					ans = ans * 1000 + num;
				if (str == "million")
					ans = ans * 1000000 + num;
				num = 0;
			}
		}
		tempstr = str;
		i = j + 1;
	}
	ans += num;
	return ans;
}

int main()
{
	//string str = "seven hundred eighty-three thousand nine hundred and nineteen";
	//string str="twenty-five";
	//string str = "five thousand six hundred";
	//string str = "two hundred fifty thousand";
	string str = "seven hundred thousand";
	cout << parse_int(str);
	return 0;
}