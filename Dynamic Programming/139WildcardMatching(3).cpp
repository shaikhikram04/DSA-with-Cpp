//! T.C -> O(n*m)
//! S.C -> O(m)

//* Space Optimization

#include <bits/stdc++.h> 
using namespace std;

class Solution {

    bool solveSO(string& s, string& p) {
        int n = s.length();
        int m = p.length();
        
        vector<bool> next(m+1, false);
        vector<bool> curr(m+1, false);

        // base case
        next[m] = true;
        bool onlyAsterics = true;
        for (int j = m-1; j >= 0; j--) {
            if (p[j] != '*')    onlyAsterics = false;
            next[j] = onlyAsterics;
        }

        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                //* match
                if (s[i] == p[j] || p[j] == '?') 
                    curr[j] = next[j+1];
                
                else if (p[j] == '*') 
                    curr[j] = (curr[j+1] || next[j]);
                
                else
                    curr[j] = false;
            }
            next = curr;
        }

        return next[0];
    }

public:
    bool isMatch(string& s, string& p) {
        return solveSO(s, p);
    }
};