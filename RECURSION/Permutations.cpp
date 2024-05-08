//? https://leetcode.com/problems/permutations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void solve(vector<int> nums, int index, vector<vector<int>>& ans)
    {
        if(index >= nums.size()){
            ans.push_back(nums);
            return;
        }else{
            for(int i = index; i < nums.size(); i++)
            {
                swap(nums[index], nums[i]);
                solve(nums,index+1,ans);
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        solve(nums,index,ans);
        return ans;
    }
};