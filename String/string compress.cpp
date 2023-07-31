#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int compress(vector<char> ch)
{
	int i = 0;
	int ansIndex = 0;
	int n = ch.size();
	while (i < n)
	{
		int j = i + 1;
		while (j < n && ch[i] == ch[j])
		{
			j++;
		}
		ch[ansIndex++] = ch[i];
		int count = j - i;
		if (count > 1)
		{
			string cnt = to_string(count);
			
			for (char c : cnt)
				ch[ansIndex++] = c;
		}
		i = j;
	}
	
	for (char h : ch)
		cout << h << " ";
	cout << endl;
	
	return ansIndex;
}

int main()
{
	vector<char> ch = {'a', 'a', 'b', 'c', 'c', 'c', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd'};

	cout << compress(ch) << endl;
	
	return 0;
}