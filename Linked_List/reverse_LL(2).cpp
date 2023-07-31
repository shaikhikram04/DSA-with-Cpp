#include <iostream>
using namespace std;

// using recursion

class Node {
public:
    int data;
    Node* next;

    Node(int dta){
        data = dta;
        next = NULL;
    }
};

void reverse(Node* &head, Node* prev, Node* curr) {
    // base case
    if (curr == NULL) {
        head = prev;
        return;
    }

    Node* forward = curr->next;
    reverse(head,curr,forward);
    curr->next = prev;
}

Node* reverseLL(Node* head) {
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node* curr = head;
    Node* prev = NULL;
    reverse(head,prev,curr);
    return head;
}