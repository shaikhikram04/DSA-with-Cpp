// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<int> sort(vector<int> v) {
        for (int i = 1; i < v.size(); i++) {
            int num = v[i];
            int j;
            for (j = i-1; j >= 0; j--) {
                if (num < v[j]) {
                    v[j+1] = v[j];
                } else {
                    break;
                }
            }
            v[j+1] = num;
        }
        return v;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int cost = 0;
        int length = n;
        vector<int> v = sort(cuts);
        for (int i = 0; i < v.size(); i++) {
            cost += length;
            length -= v[i];
        }
        return cost;
    }
};