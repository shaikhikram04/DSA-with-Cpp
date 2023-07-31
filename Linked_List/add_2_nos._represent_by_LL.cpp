#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int dta) {
        data = dta;
        next = NULL;
    }
};

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void insertAtTail(Node* &head, Node* &tail, int value) {
    if (head != NULL) {
        Node* temp = new Node(value);
        tail->next = temp;
        tail = tail->next;
    } else {
        head = new Node(value);
        tail = head;
    }
}

Node* add(Node* first, Node* second) {
    int carry = 0, sum ,digit;
    Node* ansHead = NULL;
    Node* ansTail = ansHead;
    while (first != NULL || second != NULL || carry != 0) {
        int val1 = 0;
        if (first != NULL)
            val1 = first->data;

        int val2 = 0;
        if (second != NULL)
            val2 = second->data;

        sum = val1 + val2 + carry;
        digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
        if (first != NULL)
            first = first->next;

        if (second != NULL)
            second = second->next;
    }
    
    return ansHead;
}

//Function to add two numbers represented by linked list.
struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    first = reverse(first);
    second = reverse(second);
    Node* ans = add(first , second);
    
    return reverse(ans);
}