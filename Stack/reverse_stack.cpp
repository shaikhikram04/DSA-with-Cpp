// problem link : https://www.codingninjas.com/codestudio/problems/reverse-stack-using-recursion_631875?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio

#include <vector>
#include <stack>
using namespace std;

void reverseStack(stack<int> &stack) {
    vector<int> arr;
    while (!stack.empty()) {
        arr.push_back(stack.top());
        stack.pop();
    }
    for (int i = 0; i < arr.size(); i++) {
        stack.push(arr[i]);
    }
}