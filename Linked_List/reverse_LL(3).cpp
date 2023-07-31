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

Node* reverseLL(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* rest = reverseLL(head->next);
    head->next->next = head;
    head = rest; 
}