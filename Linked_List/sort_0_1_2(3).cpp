#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int dta){
        data = dta;
    }
};

Node* sortList(Node *head) {
    if (head == NULL)
        return head;
    
    // creating dummy nodes
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    // traverseing LL
    Node* curr = head;
    while (curr != NULL) {
        if (curr->data == 0) {
            zeroTail->next = curr;
            zeroTail = curr;
        }
        else if (curr->data == 1) {
            oneTail->next = curr;
            oneTail = curr;
        }
        else if (curr->data == 2) {
            twoTail->next = curr;
            twoTail = curr;
        }
        curr = curr->next;
    }

    // merging LL
    if (oneHead->next == NULL)
        zeroTail->next = twoHead->next;
    else
        zeroTail->next = oneHead->next;

    oneTail->next = twoHead->next;
    twoTail->next = NULL;
    // update head
    head = zeroHead->next;
    // delete dummy LL
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
}