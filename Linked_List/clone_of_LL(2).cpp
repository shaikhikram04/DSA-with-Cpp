#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* arb;

    Node(int dta){
        data = dta;
        next = NULL;
        arb = NULL;
    }
};

void insertAtTail(Node* &tail, int dta) {
    Node* temp = new Node(dta);
    tail->next = temp;
    tail = temp;
}

Node *copyList(Node *head) {
    Node* cloneHead = new Node(head->data);
    Node* cloneTail = cloneHead;
    // creating clone LL using only next pointer
    Node* curr = head->next;
    while (curr != NULL) {
        insertAtTail(cloneTail, curr->data);
        curr = curr->next;
    }

    // pointing next of original node to the correspponding clone node
    // and next of clone node to the next of corresponding original node
    Node* originalNode = head;
    Node* cloneNode = cloneHead;
    while (originalNode != NULL) {
        Node* originalNext = originalNode->next;
        originalNode->next = cloneNode;

        Node* cloneNext = cloneNode->next;
        cloneNode->next = originalNext;

        originalNode = originalNext;
        cloneNode = cloneNext;
    }
    // join random of clone node
    Node* temp = head;
    while (temp != NULL) {
        if (temp->next != NULL){
            if (temp->arb != NULL)
                temp->next->arb = temp->arb->next;
            else
                temp->next->arb = NULL;
        }
        temp = temp->next->next;
    }

    // fix original and clone LL next
    originalNode = head;
    cloneNode = cloneHead;
    while (originalNode != NULL && cloneNode != NULL) {
        originalNode->next = cloneNode->next;
        originalNode = originalNode->next;
        
        if (originalNode != NULL)
            cloneNode->next = originalNode->next;
        else
            cloneNode->next = NULL;
        cloneNode = cloneNode->next;
    }

    return cloneHead;
}