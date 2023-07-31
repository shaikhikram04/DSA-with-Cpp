#include <iostream>
#include <string>
#include <cmath>
#include <deque>
using namespace std;
string incrementString(const string &str)
{
	int num = 1, digit = 0;
	deque<char> dnum;
	deque<char> dstr;
	for (int i = str.size() - 1; i >= 0; i--)
	{
		if (str[i] >= 48 && str[i] < 58)
		{
			dnum.push_front(str[i]);
		}
		else
		{
			for (int j = i; j >= 0; j--)
			{
				dstr.push_front(str[j]);
			}
			break;
		}
	}

	string n(dnum.begin(), dnum.end());
	string newstr(dstr.begin(), dstr.end());

	if (n.size() > 0)
	{
		num = 0;
		for (int a = 0; a < n.size(); a++)
		{
			num = num * 10 + n[a] - 48;
		}
		digit = n.size() - 1;
		num++;
		int temp = n.size();
		if (pow(10, temp) == num && n.front() != '0')
		{
			cout << "increment of digit" << endl;
			digit++;
		}
		n.clear();
	}

	for (int i = digit; i >= 0; i--)
	{
		int p = pow(10, i);
		char temp = num / p + 48;
		n.push_back(temp);
		num = num % p;
	}

	return newstr + n;
}

int main()
{
	//string str = "foo";
	//string str = "foobar23";
	//string str = "foo0042";
	//string str = "foo9";
	//string str = "foo099";
	//string str = "1";
	//string str = "fo99obar99";
	string str = "fqstlbvaadixytytrmygiksphnbovwpi299";
	cout << incrementString(str);
	return 0;
}