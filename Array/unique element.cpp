#include <iostream>
#include <vector>
using namespace std;

float find_uniq(const vector<float> &v)
{
	float ans;
	for (int i = 0; i < v.size(); i++)
	{
		int count = 0;
		for (int j = 0; j < v.size(); j++)
		{
			if (i == j)
				continue;

			if (v[i] == v[j])
				break;

			else
				count++;
		}
		if (count == v.size() - 1)
			ans = v[i];
	}
	return ans;
}

int main()
{
	vector<float> arr = {0, 0, 0, 2};
	float unique = find_uniq(arr);
	cout << unique << endl;
	return 0;
}