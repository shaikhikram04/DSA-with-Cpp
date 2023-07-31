// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

#include <vector>
#include <queue>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
    queue<long long int> q;
    vector<long long> ans;
    for (int i = 0; i < K; i++) {
        if (A[i] < 0) {
            q.push(i);
        }
    }
    if (q.size() > 0) {
        ans.push_back(A[q.front()]);
    } else {
        ans.push_back(0);
    }

    for (int i = K; i < N; i++) {
        // removing 1st element of previous window if present
        if (!q.empty() && i - q.front() >= K) {
            q.pop();
        }
        // inserting next element into window
        if (A[i] < 0) {
            q.push(i);
        }

        if (q.size() > 0) {
            ans.push_back(A[q.front()]);
        } else {
            ans.push_back(0);
        }
    }    
    return ans;                                      
 }