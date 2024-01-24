//! T.C -> O(n^2)
//! S.C -> O(n)

//* Space Optimization

#include <bits/stdc++.h> 
using namespace std;

class Solution {

    int solveSO(string s) {
        int n = s.length();

        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);

        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                int len = (i != j) ? 2 : 1;

                if (s[i] == s[j]) {
                    curr[j+1] = len + next[j];
                }
                else {
                    curr[j+1] = max(next[j+1], curr[j]);
                }
            }
            next = curr;
        }

        return curr[n];
    }

public:
    int longestPalindromeSubseq(string s) {
        return solveSO(s);
    }
};