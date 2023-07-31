// https://www.codingninjas.com/codestudio/problem-of-the-day/moderate

#include <bits/stdc++.h> 
using namespace std;

int getMinimumAnagramDifference(string &str1, string &str2) {
    unordered_map<char, int> cnt;
    int diffreence = 0;
    for (int i = 0; i < str1.length(); i++) {
        char ch = str1[i];
        if (cnt.count(ch)) {
            cnt[ch]++;
        } else {
            cnt[ch] = 1;
        }
    }

    for (int i = 0; i < str2.size(); i++) {
        char ch = str2[i];
        if (cnt.count(ch)) {
            if (cnt[ch] == 0) {
                diffreence++;
            } else {
                cnt[ch]--;
            }
        } else {
            diffreence++;
        }
    }
    return diffreence;
}