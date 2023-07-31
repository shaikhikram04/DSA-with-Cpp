#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int ans;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (cnt.count(num)) {
                return num;
            }
            cnt[num] = 1;
        }
        return -1;
    }
};
