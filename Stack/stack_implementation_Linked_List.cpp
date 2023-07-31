#include <iostream>
using namespace std;

class Node {
public: 
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class Stack {
    // properties
    Node* head;
    Node* tail;
    int top;
    int size;

    void insertAtTail(Node* &head, Node* &tail, int dta) {
        Node* newNode = new Node(dta);
        // empty list
        if (head == NULL) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    void deleteTail(Node* &head, Node* &tail) {
        Node* temp = tail;
        if (head->next == NULL) {
            head = NULL;
            tail = head;
            delete temp;
        } else {
            Node* curr = head->next;
            while (curr->next != tail) {
                curr = curr->next;
            }
            tail = curr;
            tail->next = NULL;
            delete temp;
        }
    }

public: 
    // behaviour
    Stack(int size) {
        head = NULL;
        tail = head;
        this->size =  size;
        top = 0;
    }

    void push(int element) {
        if (top + 1 <= size) {
            top++;
            insertAtTail(head, tail, element);
        } else {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop() {
        if (top > 0) {
            deleteTail(head, tail);
        } else {
            cout << "Stack Underflow" << endl;
        }
    }

    int peek() {
        if (top > 0) {
            return tail->data;
        } else {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    bool empty() {
        return (top == 0);
    }

    void print() {
        Node* curr = head;
        while(curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() 
{
    Stack s(5);
    s.push(77);
    s.push(54);
    s.push(87);
    s.push(61);
    s.push(48);
    // s.push(73);

    s.pop();

    cout << "top of stack is -> " << s.peek() << endl;
    s.print();

    if (s.empty()) {
        cout << "stack is empty" << endl;
    } else {
        cout << "stack is not empty" << endl;
    }

    return 0;
}