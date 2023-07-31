// problem link : https://www.codingninjas.com/codestudio/problems/delete-middle-element-from-stack_985246?leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio

#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &inputStack,int count, int mid) {
    // removing midle element
    if (mid == count) {
        inputStack.pop();
        return;
    }
    // store top element for reinsert into stack
    int temp = inputStack.top();
    inputStack.pop();
    // recursive call
    solve(inputStack, count + 1, mid);
    // inserting non middle element
    inputStack.push(temp);
}

void deleteMiddle(stack<int> &inputStack, int N)
{
    int mid = N / 2;
    int count = 0;
    solve(inputStack, count, mid);
}