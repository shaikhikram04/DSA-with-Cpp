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

// problem link : https://www.codingninjas.com/codestudio/problems/split-a-circular-linked-list_1071003

void splitCircularList(Node *head)
{
    Node* slow = head;
    Node* fast = head->next;
    while (fast->next == head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    fast->next = slow->next;
    slow->next = head;
    return;
}

// problem link : https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node* slow = head;
    Node* fast = head->next;
    while (fast->next != head) {
        slow = slow->next;
        fast = fast->next;
        if (fast->next != head)
            fast = fast->next;
    }
    *head1_ref = head;
    *head2_ref = slow->next;
    fast->next = slow->next;
    slow->next = head;
    return;
}