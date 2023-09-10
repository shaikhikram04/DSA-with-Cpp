// https://www.codingninjas.com/studio/problems/longest-common-prefix_2090383


// itrative
// T.C -> O(M*N)
// S.C -> O(1)


#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";
    
    int minStrSize = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (arr[i].size() < minStrSize) {
            minStrSize = arr[i].size();
        }
    }

    for (int i = 0; i < minStrSize; i++) {
        char ch = arr[0][i];
        bool isSame = true;
        for (int j = 1; j < n; j++) {
            if (arr[j][i] != ch) {
                isSame = false;
                break;
            }
        }
        if (isSame)
            ans.push_back(ch);
        else {
            break;
        }
    }

    return ans;
}


