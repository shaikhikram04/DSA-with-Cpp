#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void move_zero(vector<int> v)
{
	int s = v.size();
	int a = 0, b = s - 1;
	while (a < b)
	{
		if (v[a] != 0)
			a++;
		else if (v.at(b) == 0)
			b--;
		else if (v.at(a) == 0 && v.at(b) != 0)
		{
			rotate((v.begin() + a), (v.begin() + a) + 1, v.end());
			a++;
			b--;
		}
	}
	for (int i = 0; i < s; i++)
		cout << v.at(i) << "  ";
	cout << endl;
}

int main()
{
	vector<int> arr = {2, 0, 1, 3, 0, 0, 0};
	move_zero(arr);
	return 0;
}