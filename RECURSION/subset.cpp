#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans)
{
	// base case
	if (index >= nums.size())
	{
		ans.push_back(output);
		return;
	}

	// exclude index element
	solve(nums, output, index + 1, ans);

	// include index element
	output.push_back(nums[index]);
	solve(nums, output, index + 1, ans);
}

// TIME COMPLEXITY  --> O(n)
// SPACE COMPLEXITY --> O(n)
vector<vector<int>> powerSet(vector<int> nums)
{
	vector<vector<int>> ans;
	vector<int> output;
	int index = 0;
	solve(nums, output, index, ans);

	return ans;
}

int main()
{
	vector<int> nums = {1, 2, 3, 4};

	vector<vector<int>> ans = powerSet(nums);

	for (int i = 0; i < pow(2, nums.size()); i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
		{
			cout << ans[i][j] << ",";
		}
		cout << endl;
	}
	return 0;
}