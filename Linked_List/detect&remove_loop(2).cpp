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

Node* floydDetectLoop(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) {
            return fast;
        }
    }
    return NULL;
}

Node *removeLoop(Node *head)
{
    Node* intersect = floydDetectLoop(head);
    if (intersect == NULL) 
        return head;
    if (intersect == head) {
        while (intersect->next != head) {
            intersect = intersect->next;
        }
    } else {
        Node* slow = head;
        while (intersect != slow) {
            slow = slow->next;
            if (intersect->next == slow) {
                break;
            }
            intersect = intersect->next;
        }
    }
    intersect->next = NULL;
    return head;
}