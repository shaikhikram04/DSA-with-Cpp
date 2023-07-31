#include <iostream>
using namespace std;

class Stack {

    // property
    int *arr;
    int top;
    int size;

public:
    // behaviour
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element) {
        if (size - top < 1) {
            arr[++top] = element;
        } else {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop() {
        if (top >= 0) {
            top--;
        } else {
            cout << "Stack Underflow" << endl;
        }
    }

    int peek() {
        if (top >= 0){
            return arr[top];
        } else {
            cout << "stack is empty" << endl;
            return -1;
        }
    }

    bool empty() {
        return (top == -1);
    }

    void print() {
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

int main() 
{
    Stack s(6);
    s.push(4);
    s.push(9);
    s.push(13);

    s.pop();
    s.pop();
    s.pop();
    cout << "top of stack -> " << s.peek() << endl;
    s.print();
    if (s.empty()) {
        cout << "stack is empty" << endl;
    } else {
        cout << "stack is not empty" << endl;
    }

    return 0;
} 