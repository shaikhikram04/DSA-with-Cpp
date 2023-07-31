// problem link : https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio

#include <bits/stdc++.h> 
using namespace std;

void insertInSortedWay(stack<int> &stack, int num) {
    // base case
    // if stack is empty then push element
    if (stack.empty()) {
        stack.push(num);
        return;
    }
    // found right place to insert
    if (stack.top() <= num) {
        stack.push(num);
        return;
    }

    int temp = stack.top();
    stack.pop();
    insertInSortedWay(stack, num);
    stack.push(temp);
}

void sortStack(stack<int> &stack)
{
	if (stack.empty())
		return;

    int num = stack.top();
    stack.pop();
    sortStack(stack);

    insertInSortedWay(stack, num);
}