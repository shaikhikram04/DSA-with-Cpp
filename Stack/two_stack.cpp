// problem link : https://www.codingninjas.com/codestudio/problems/two-stacks_983634?leftPanelTab=0&campaign=YouTube_CodestudioLovebabbar5thfeb&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_CodestudioLovebabbar5thfeb

#include <bits/stdc++.h> 
class TwoStack {
    int *arr;
    int top1;
    int top2;
    int size;

public:

    // Initialize TwoStack.
    TwoStack(int s) {
        arr = new int[s];
        top1 = -1;
        top2 = s;
        size = s;
    }
    
    // Push in stack 1.
    void push1(int num) {
        if (top2 - top1 > 1){
            arr[++top1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if (top2 - top1 > 1) {
            arr[--top2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if (top1 >= 0) {
            int ans = arr[top1--];
            return ans;
        } else {
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if (top2 < size) {
            int ans = arr[top2++];
            return ans;
        } else {
            return -1;
        }
    }
};
