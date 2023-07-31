// https://practice.geeksforgeeks.org/problems/queue-reversal/1

#include <queue>
#include <stack>
using namespace std;

queue<int> rev(queue<int> q)
{
    stack<int> s;
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    return q;
}