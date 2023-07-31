// problem link : https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1


#include <vector>
using namespace std;

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
    
        for (int i = 0; i < n; i++) {
            int cnt1 = 0;
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                if(M[i][j] == 1) {
                    cnt1++;
                    break;
                }
            }
            if (cnt1 == 0) {
                for (int k = 0; k < n; k++) {
                    if (k == i)
                        continue;

                    if(M[k][i] == 1) 
                        cnt1++;
                }
                if (cnt1 == n-1)
                    return i;
            }
        }
        return -1;
    }
};