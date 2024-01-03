//! T.C -> O(n)
//! S.C -> O(1)

//* Space Optimization

#include <bits/stdc++.h> 
using namespace std;

class Solution {

public:
    int longestArithSeqLength(vector<int>& nums) {
        int max = 2;
        int size = nums.size();
        for (int i = 0; size - i > max; i++){
            for (int j = i+1; size - j >= max; j++) {
                int diff = nums[j]-nums[i];
                int cnt = 2;
                int next = nums[j] + diff;
                for (int k = j+1; size-k+cnt > max && k < size && next >= 0 && next <= 500; k++) {
                    if (next == nums[k]) {
                        next = nums[k] + diff;
                        cnt++;
                    }
                }
                if (max < cnt) max = cnt;
            }
        }

        return max;
    }
};