#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> powerSet(vector<int> nums)
{
    int bit = nums.size();
    int allBit = pow(2, bit);

    vector<vector<int>> ans;

    for (int i = 0; i < allBit; i++)
    {
        vector<int> output;
        for (int j = 0; j < bit; j++)
        {
            if ( (i >> j) & 1){
                output.push_back(nums[j]);
            }
        }
        ans.push_back(output);
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans = powerSet(nums);

    for (int i = 0; i < pow(2, nums.size()); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}