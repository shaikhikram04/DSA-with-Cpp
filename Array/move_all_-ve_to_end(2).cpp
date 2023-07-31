#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void segregateElements(int arr[], int n)
    {
        vector<int> positive;
        vector<int> negative;
        for (int i = 0; i < n; i++) {
            if (arr[i] < 0) {
                negative.push_back(arr[i]);
            } else {
                positive.push_back(arr[i]);
            }
        }
        int i = 0;
        int j = 0;
        while (j < positive.size()) {
            arr[i++] = positive[j++];
        }
        j = 0;
        while (j < negative.size()) {
            arr[i++] = negative[j++];
        }
    }
};