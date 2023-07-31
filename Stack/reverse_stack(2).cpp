#include <stack>
using namespace std;

void insertAtBottom(stack<int> &stack, int num)
{
    if (stack.empty())
    {
        stack.push(num);
        return;
    }
    int temp = stack.top();
    stack.pop();
    insertAtBottom(stack, num);

    stack.push(temp);
}

void reverseStack(stack<int> &stack)
{
    if (stack.empty())
    {
        return;
    }
    int num = stack.top();
    stack.pop();

    reverseStack(stack);

    insertAtBottom(stack, num);
}