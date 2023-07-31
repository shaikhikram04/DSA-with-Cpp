// https://www.codingninjas.com/codestudio/problems/interleave-the-first-half-of-the-queue-with-the-second-half_1169450

#include <bits/stdc++.h> 
using namespace std;

void interLeaveQueue(queue < int > & q) {
    stack<int> s;
    int n = q.size();
    while(q.size() > n/2) {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    for (int i = 0; i < n/2; i++) {
        q.push(q.front());
        q.pop();
    }
    while(q.size() > n/2) {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}