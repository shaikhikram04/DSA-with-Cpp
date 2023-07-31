// https://leetcode.com/problems/implement-stack-using-queues/description/

#include <queue>
using namespace std;

class MyStack {
    queue<int> q;
    queue<int> tempQ;
    
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        while (q.size() > 1) {
            tempQ.push(q.front());
            q.pop();
        }
        int ans = q.front();
        q.pop();
        while (!tempQ.empty()){
            q.push(tempQ.front());
            tempQ.pop();
        }
        return ans;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */