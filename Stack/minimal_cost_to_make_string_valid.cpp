// problem link : https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770?leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio

#include <bits/stdc++.h>
using namespace std;

int findMinimumCost(string str)
{
    // str length is odd
    if (str.length() % 2 == 1) {
        return -1;
    }
    int n = str.length();
    int cost = 0;
    stack<char> s;

    for (int i = 0; i < n; i++) {
        char ch = str[i];
        if (ch == '{') {
            if (n - i <= s.size()) {
                cost++;
                s.pop();
            } else {
                s.push(ch);
            }
        } else {
            if (s.empty()) {
                cost++;
                s.push('{');
            } else {
                s.pop();
            }
        }

    }
    return cost;
}