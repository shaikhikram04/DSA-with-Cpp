//? https://leetcode.com/problems/maximal-rectangle/submissions/1160211885/

//! T.C -> O(n*m)
//! S.C -> O(n*m)

//* Previous & Next Smallest Element Approach

#include <bits/stdc++.h> 
using namespace std;

class Solution {
    //! finding previous smallest element of each element of given array using Monotonic Stack
    vector<int> prevSmallestElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n); //* Declare ans array of size n

        stack<int> s; //* declare a monotonic Stack
        s.push(-1); //* Initialy push -1 because here is no previous of first element
        
        //! Solve for each element
        for (int i = 0; i < n; i++) {
            int ele = arr[i];
            //* pop ele from stack if top of stack index element is greater or equal to curr ele OR there is only 1 ele -1.
            while (s.top() != -1 && arr[s.top()] >= ele) {
                s.pop();
            }
            //* Store previos smallest element index in ans array which is present at the top of the stock
            ans[i] = s.top();
            //* Push curr index in stack
            s.push(i);
        }

        //* return ans array
        return ans;
    }

    //! finding next smallest element of each element of given array using Monotonic Stack
    vector<int> nextSmallestElement(vector<int>& arr) {
        int n = arr.size(); 
        vector<int> ans(n); //* Declare ans array of size n

        stack<int> s; //* declare a monotonic Stack
        s.push(n); //* Initialy push n because here is no next of last element

        //! Solve for each element
        for (int i = n-1; i >= 0; i--) {
            int ele = arr[i];
            //* pop ele from stack if top of stack index element is greater or equal to curr ele OR there is only 1 ele n.
            while (s.top() != n && arr[s.top()] >= ele) {
                s.pop();
            }
            //* Store next smallest element index in ans array which is present at the top of the stock
            ans[i] = s.top();
            //* Push curr index in stack
            s.push(i);
        }

        //* return ans array
        return ans;
    }

    int largestArea(vector<int>& height) {
        int n = height.size();

        //* Find previous smaller element of height array
        vector<int> prev = prevSmallestElement(height);
        //* Find next smaller element of height array
        vector<int> next = nextSmallestElement(height);

        //? It Store maxArea of histogram
        int maxArea = 0;

        //* For each height, take height as lenght and finding breadth using prev & next then find area
        for (int i = 0; i < n; i++) {
            //? lenght
            int l = height[i];
            //? breadth
            int b = next[i] - prev[i] - 1;
            //? area
            int area = l * b;
            //* handle maxArea
            maxArea = max(maxArea, area);
        }

        //* return maximim area
        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        //* Create a height array of size equal to no. of column of matrix initialize with all 0
        //* Actually here we going to convert given matrix into a histogram
        vector<int> height(matrix[0].size(), 0);

        int maxAns = 0;

        //* Traversing each row of matrix
        for (int i = 0; i < matrix.size(); i++) {
            //* handling height array
            for (int j = 0; j < height.size(); j++) {
                //* if element is 1 then increment height
                if (matrix[i][j] == '1') {
                    height[j]++;
                }
                //* Otherwise update it as 0
                else {
                    height[j] = 0;
                }
            }
            //* Find ans of current row
            int ans = largestArea(height);

            //* Handle maxAns
            maxAns = max(maxAns, ans);

        }

        //? return maximim area with all 1's
        return maxAns;
    }
};