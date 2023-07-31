#include <bits/stdc++.h> 
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

class Queue {
    void insertAtTail(Node* &head, Node* &tail, int dta) {
        Node* temp = new Node(dta);
        if (head == NULL) {
            head = temp;
            tail = head;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    void deleteHead(Node* &head, Node* &tail) {
        Node* temp = head;
        if (head == tail) {
            head = NULL;
            tail = head;
        } else {
            head = head->next;
        }
        temp->next = NULL;
        delete temp;
    }

    Node* head;
    Node* tail;
    
public:
    Queue() {
        head = NULL;
        tail = head;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return (head == NULL);
    }

    void enqueue(int data) {
        insertAtTail(head, tail, data);
    }

    int dequeue() {
        if (head == NULL) {
            return -1;
        }
        int ans = head->data;
        deleteHead(head, tail);
        return ans;
    }

    int front() {
        if (head == NULL) {
            return -1;
        }
        return head->data;
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

int main(){
    Queue q;
    cout << "front -> " << q.front() << endl;
    cout << "poped element -> " << q.dequeue() << endl;
    q.enqueue(17);
    q.enqueue(23);
    q.enqueue(11);
    cout << "front -> " << q.front() << endl;
    q.print();
    cout << "poped element -> " << q.dequeue() << endl;

    return 0;
}