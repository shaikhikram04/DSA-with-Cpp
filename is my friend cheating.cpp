#include <iostream>
#include <vector>

using namespace std;

class RemovedNumbers
{
  public:
	static vector<vector<long long>> removNb(long long n);
};

vector<vector<long long>> RemovedNumbers::removNb(long long n)
{
	vector<vector<long long>> v;
	vector<long long> temp;
	long long a = 1, b = n;
	long long prod;
	long long s;
	long long sum = (n * (n + 1)) / 2;
	while (a < b)
	{
		prod = a * b;
		s = a + b;
		if (prod == sum - s)
		{
			temp.push_back(a);
			temp.push_back(b);
			v.push_back(temp);
			temp.clear();
			a++;
			b--;
		}
		else if (prod < sum - s)
			a++;

		else if (prod > sum - s)
			b--;
	}
	int size = v.size();
	for (int i = size - 1; i >= 0; i--)
	{
		temp.push_back(v[i][1]);
		temp.push_back(v[i][0]);
		v.push_back(temp);
		temp.clear();
	}
	return v;
}

int main()
{
	RemovedNumbers obj;
	obj.removNb(26);
	return 0;
}