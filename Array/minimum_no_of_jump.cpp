// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        int minJumpCount = 0;
        int i = 0;
        if (nums[i] == 0 || size == 1) {
            return 0;
        }
        while (i < size) {
            int maxJump = nums[i];
            if (i + nums[i] >= size - 1) {
                return minJumpCount + 1;
            }
            int j = i + 1;
            int jumpTo = j;
            while (maxJump--) {
                if (j + nums[j] > jumpTo + nums[jumpTo] && nums[j] != 0) {
                    jumpTo = j;
                }
                j++;
            }
            i = jumpTo;
            minJumpCount++;
        }
        return minJumpCount;
    }
};

int main() {
    vector<int> arr = {2, 3, 1, 1, 2, 4, 2, 0, 1, 1};
    Solution s;
    cout << s.jump(arr) << endl;

    return 0;
}