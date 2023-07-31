// https://leetcode.com/problems/find-the-duplicate-number/description/

#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        vector<int> arr(n, 0);
        int ans;
        for (int i = 0; i <= n; i++) {
            if (arr[nums[i] - 1] == 1) {
                ans = nums[i];
            }
            arr[nums[i] - 1]++;
        }
        return ans;
    }
};