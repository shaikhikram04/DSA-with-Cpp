#include <iostream>
#include <vector>
using namespace std;

void MoveZero(vector<int> v)
{
	int i = 0;
	for (int c = 0; c < v.size(); c++)
	{
		if (v[c] != 0)
		{
			swap(v[i], v[c]);
			i++;
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "  ";
	}
}

int main()
{
	vector<int> arr = {2, 0, 1, 3, 0, 0, 0};
	MoveZero(arr);
	return 0;
}