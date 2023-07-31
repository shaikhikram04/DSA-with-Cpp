// https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

#include <queue>
#include <stack>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> s;
    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }
    
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    for (int i = 0; i < q.size() - k; i++) {
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
}