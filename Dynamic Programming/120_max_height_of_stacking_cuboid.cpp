//? https://leetcode.com/problems/maximum-height-by-stacking-cuboids/description/

//! T.C -> O(n*n)
//! S.C -> O(n)

//* Space Optimization

#include <bits/stdc++.h> 
using namespace std;

class Solution {

    int solveSO(int n, vector<vector<int>>& c) {
        vector<int> currRow(n+1, 0);

        for (int curr = n-1; curr >= 0; curr--) {
            int B = c[curr][1], H = c[curr][2];

            for (int prev = -1; prev < curr; prev++) {
                //* include
                int inc = 0;
                //* check is there is no previous cuboid OR curr cuboid L, B and H greater than previous cuboid
                if (prev == -1 || (B >= c[prev][1] && H >= c[prev][2]))
                    //* if include then previous become curr
                    inc = c[curr][2] + currRow[curr+1]; //* Then add curr cuboid height to previous stored ans

                //* exclude
                //* if exclude then previoius remain previous
                int exc = currRow[prev+1];

                //* store max of inc and exc in result
                currRow[prev+1] = max(inc, exc);
            }
        }
        //* return ans when we start from 0th index
        return currRow[0];
    }

public:
    int maxHeight(vector<vector<int>>& cuboids) {
        //* sort each subarray
        for (int i = 0; i < cuboids.size(); i++) {
            sort(cuboids[i].begin(), cuboids[i].end());
        }

        //* sort array
        sort(cuboids.begin(), cuboids.end());

        return solveSO(cuboids.size(), cuboids);
    }
};