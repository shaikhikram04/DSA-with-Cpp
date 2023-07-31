#include <vector>
#include <cstdlib>
using namespace std;
vector<vector<int>> pyramid(int n)
{
	vector<vector<int>> ans;
	for (int i = 0; i < n; i++)
	{
		vector<int> v1;
		for (int j = 0; j <= i; j++)
		{
			v1.push_back(1);
		}
		ans.push_back(v1);
	}
	return ans;
}
int main()
{
	pyramid(5);
	return 0;
}