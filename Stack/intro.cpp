#include <iostream>
#include <stack>

using namespace std;

int main()
{
    // creating stack
    stack<int> s;

    // insert data into stack
    s.push(1);
    s.push(5);
    s.push(7);

    // revove data from stack
    s.pop();

    // top element 
    cout << "top element -> " << s.top() << endl;
    // check stack is empty or not
    cout << "is empty -> " << s.empty() << endl;

    // printing size of stack
    cout << "size of stack is " << s.size() << endl; 

    return 0;
}