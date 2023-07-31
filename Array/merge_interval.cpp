// https://leetcode.com/problems/merge-intervals/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int n = intervals.size();

        int f1 = intervals[0][0];
        int s1 = intervals[0][1];

        for (int i = 1; i < n; i++) {
            
            if (intervals[i][0] <= s1) {
                s1 = max(s1, intervals[i][1]);
            } else {
                ans.push_back({f1, s1});
                f1 = intervals[i][0];
                s1 = intervals[i][1];
            }
        }
        ans.push_back({f1, s1});
        return ans;
    }
};

int main() {

    vector<vector<int>> intervals = {{1,4}, {4,5}};

    Solution s;

    vector<vector<int>> ans = s.merge(intervals);
    cout << "after merged" << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i][0] << "  " << ans[i][1] << endl;
    }
    cout << endl;

    return 0;
}