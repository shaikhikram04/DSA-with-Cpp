// https://www.codingninjas.com/codestudio/problems/interleave-the-first-half-of-the-queue-with-the-second-half_1169450

#include <bits/stdc++.h> 
using namespace std;

void interLeaveQueue(queue <int> & q) {
    int n = q.size();
    queue<int> newQ;
    while (q.size() > n/2){
        newQ.push(q.front());
        q.pop();
    }
    while (!newQ.empty()) {
        q.push(newQ.front());
        newQ.pop();
        q.push(q.front());
        q.pop();
    }
}