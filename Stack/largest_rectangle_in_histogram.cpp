//? problem link : https://leetcode.com/problems/largest-rectangle-in-histogram/

#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        
        for (int i = 0; i < heights.size(); i++) {
            int l = heights[i];
            int b = 1;
            for (int j = i - 1; j >= 0 ; j--) {
                if (heights[j] >= l) {
                    b++;
                } else {
                    break;
                }
            }
            for (int j = i + 1; j < heights.size(); j++) {
                if (heights[j] >= l) {
                    b++;
                } else {
                    break;
                }
            }
            int area = l * b;
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};