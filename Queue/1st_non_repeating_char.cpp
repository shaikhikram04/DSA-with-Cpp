//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        // count occurance of letter
        int count[26] = {0};
        queue<char> q;
        for (int i = 0; i < A.length(); i++)
        {
            // increment count for A[i]
            count[A[i] - 'a']++;
            // push letter into queue
            q.push(A[i]);

            // pop queue until first element is repeated
            while (!q.empty() && count[q.front() - 'a'] > 1)
            {
                q.pop();
            }
            // after pop if queue is empty then print #
            if (q.empty())
            {
                A[i] = '#';
            }
            else
            {
                A[i] = q.front();
            }
        }
        return A;
    }
};

//{ Driver Code Starts.
int main()
{

    string A = "aabc";
    Solution obj;
    string ans = obj.FirstNonRepeating(A);
    cout << ans << "\n";

    return 0;
}

// } Driver Code Ends