#include <iostream>
#include <vector>
#include <array>
using namespace std;

vector<vector<int>> pairSum(vector<int> arr, int s)
{
	vector<vector<int>> ans;
	for (int i = 0; i < arr.size() - 1; i++)
	{
		for (int j = 0; j < arr.size(); j++)
		{
			if (arr[i] == arr[j])
			{
				vector<int> temp;
				temp.push_back(min(arr[i], arr[j]));
				temp.push_back(min(arr[i], arr[j]));
				ans.push_back(temp);
			}
		}
	}
	sort(ans.begin(),ans.end());
	return ans;
}

int main()
{
	vector<int> arr={2, -3, 3, 3, -2};
	vector<vector<int>> ans=pairSum(arr,0);
	for (int p = 0; p < ans.size(); p++)
	{
		for (int q = 0; q <= 1; q++)
		{
			cout << ans[p][q] << "   ";
		}
		cout << endl;
	}
	return 0;
}