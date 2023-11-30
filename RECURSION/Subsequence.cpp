#include <iostream>
#include <vector>
#include <string>
using namespace std;

int power2(int n)
{
	if (n == 0)
		return 1;

	return 2 * power2(n - 1);
}

void solve(string str, string output, int index, vector<string> &subSeq)
{
	//* base case
	if (index >= str.length())
	{
		if (output.length() > 0)
		{
			subSeq.push_back(output);
		}
		return;
	}

	//* exclude index element
	solve(str, output, index + 1, subSeq);

	//* include index element
	output.push_back(str[index]);
	solve(str, output, index + 1, subSeq);
}

//! TIME COMPLEXITY  --> O(n)
//! SPACE COMPLEXITY --> O(n)
vector<string> subsequences(string str)
{
	vector<string> subSeq;
	string output = "";
	int index = 0;

	solve(str, output, index, subSeq);

	return subSeq;
}

int main()
{
	string str = "abc";
	vector<string> subSeq = subsequences(str);
	int n = power2(3) - 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < subSeq[i].length(); j++)
		{
			cout << subSeq[i][j] << ", ";
		}
		cout << endl;
	}

	return 0;
}