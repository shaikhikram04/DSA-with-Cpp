// problem link : https://practice.geeksforgeeks.org/problems/max-rectangle/1

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution{
  private:
    vector<int> nextSmallerElement(int *arr, int m) {
        stack<int> s;
        vector<int> ans(m);
        s.push(-1);
        for (int i = m - 1; i >= 0; i--) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(int *arr, int m) {
        stack<int> s;
        vector<int> ans(m);
        s.push(-1);
        for (int i = 0; i < m; i++) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }    

    int largestRectangularArea(int *height,int n) {
        vector<int> next = nextSmallerElement(height, n);
        vector<int> prev = prevSmallerElement(height, n);
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int l = height[i];
            if (next[i] == -1)
                next[i] = n;
            int b = next[i] - prev[i] - 1;
            int area = l * b;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
  public:
    int maxArea(int M[100][100], int n, int m) {
        // get area for 0th row
        int area = largestRectangularArea(M[0], m);
        // get area for all row next to 0th row and compare with 0th row area
        for (int i = 1; i < n; i++) {
            // updating i-th row for geting largest rectangular area 
            for (int j = 0; j < m; j++) {
                if (M[i][j] == 1) {
                    M[i][j] += M[i-1][j];
                }
            }
            int newArea = largestRectangularArea(M[i], m);
            area = max(area, newArea);
        }
        return area;
    }
};