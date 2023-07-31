// https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1

#include <vector>
#include <queue>
using namespace std;

class Solution{
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        priority_queue<int> pq;
        vector<int> ans;
        
        for (int i = 0; i < n; i++) {
            pq.push(a[i]);
        }
        for (int i = 0; i < m; i++) {
            pq.push(b[i]);
        }
        
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        
        return ans;
    }
};