#include <iostream>
#include <vector>

using namespace std;

long long findD(vector<vector<long long>> m, int i, int j);
long long determinant(vector<vector<long long>> m)
{
	int D = 0, s = m.size();
	if (s == 1)
	{
		return m[0][0];
	}
	else if (s == 2)
	{
		D += m[0][0] * m[1][1] - m[0][1] * m[1][0];
		return D;
	}
	else
	{
		int i = 0;
		for (int j = 0; j < s; j++)
		{
			if (j % 2 == 0)
				D += m[i][j] * findD(m, i, j);
			else
				D -= m[i][j] * findD(m, i, j);
		}
	}
	return D;
}

long long findD(vector<vector<long long>> m, int i, int j)
{
	int s = m.size();
	vector<vector<long long>> det;
	vector<long long> temp;
	for (int p = 1; p < s; p++)
	{
		for (int q = 0; q < s; q++)
		{
			if (p == i || q == j)
			{
				continue;
			}
			temp.push_back(m[p][q]);
		}
		det.push_back(temp);
		temp.clear();
	}
	return determinant(det);
}

int main()
{
	vector<vector<long long>> m = {{2, 5, 3}, {1, -2, -1}, {1, 3, 4}};
	cout << determinant(m);

	return 0;
}
