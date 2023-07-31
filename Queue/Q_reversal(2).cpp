#include <queue>
using namespace std;

void reverseQ (queue<int> &q) {
    // base case
    if (q.size() == 1) {
        return;
    }
    int front = q.front();
    q.pop();
    reverseQ(q);
    q.push(front);
}
 
queue<int> rev(queue<int> q) {
    reverseQ(q);
    return q;
}