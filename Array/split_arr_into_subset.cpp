// https://www.codingninjas.com/codestudio/problem-of-the-day/moderate?leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

bool isPossibleToSplit(int n, vector<int> &arr) {
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i++){
        int num = arr[i];
        if (cnt.count(num)) {
            cnt[num]++;
        } else {
            cnt[num] = 1;
        }
    }
    int count = cnt[arr[0]];
    for (auto i : cnt) {
        if (i.second != count || i.second <= 1) {
            return false;
        }
    }

    return true;
}