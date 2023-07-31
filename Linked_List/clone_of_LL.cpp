#include <iostream>
#include <unordered_map>
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
    Node* curr = head->next;
    Node* clone = new Node(head->data);
    Node* cloneTail = clone;
    while (curr != NULL)  {
        insertAtTail(cloneTail, curr->data);
        curr = curr->next;
    }
    unordered_map<Node*, Node*> mapping;
    Node* curr1 = head;
    Node* curr2 = clone;
    while (curr1 != NULL && curr2 != NULL) {
        mapping[curr1] = curr2;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    Node* originalNode = head;
    Node* cloneNode = clone;
    while (cloneNode != NULL) {
        cloneNode->arb = mapping[originalNode->arb];
        cloneNode = cloneNode->next;
        originalNode = originalNode->next;
    }
    return clone;
}