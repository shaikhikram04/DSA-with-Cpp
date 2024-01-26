//! T.C -> O(n*m)
//! S.C -> O(m)

//* Space Optimization

#include <bits/stdc++.h> 
using namespace std;

class Solution {

    int solveSO(string& a, string& b) {
        int n = a.length();
        int m = b.length();

        vector<int> curr(m+1, 0);
        vector<int> next(m+1, 0);

        //* analyse and store base case
        for (int j = 0; j < m; j++) {
            next[j] = m - j;
        }

        for (int i = n-1; i >= 0; i--) {
            curr[m] = n - i;
            for (int j = m-1; j >= 0; j--) { 
                //? if char match
                if (a[i] == b[j]) {
                    curr[j] = next[j+1];
                }
                else {
                    //* insert
                    int insertAns = 1 + curr[j+1];

                    //* delete
                    int delAns = 1 + next[j];

                    //* replace
                    int replaceAns = 1 + next[j+1];

                    curr[j] = min(insertAns, min(delAns, replaceAns));
                }
            }
            next = curr;
        }
        return next[0];
    }

public:
    int minDistance(string word1, string word2) {
        return solveSO(word1, word2);
    }
};