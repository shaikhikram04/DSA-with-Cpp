#include <vector>
#include <stack>
using namespace std;

class Solution
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        for (int i = 0; i < n; i++) {
            s.push(i);
        } 

        while (s.size() > 1) {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            if (M[a][b] == 1) {
                s.push(b);
            } else {
                s.push(a);
            }
        }
        int candidate = s.top();

        int zeroCount = 0;
        for (int i = 0; i < n; i++) {
            if (M[candidate][i] == 0) {
                zeroCount++;
            }
        }

        int oneCount = 0;
        for (int i = 0; i < n; i++) {
            if (M[i][candidate] == 1) {
                oneCount++;
            }
        }

        if (zeroCount == n && oneCount == n-1)
            return candidate;
        else {
            return -1;
        }
    }
};