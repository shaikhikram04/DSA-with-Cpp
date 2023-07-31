#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *lastAppearance(Node *head) {
    if (head == NULL)
        return head;
    Node* prev = NULL;
    Node* curr = head;
    while (curr->next != NULL) {
        bool isRemoved = false;
        Node* temp = curr->next;
        while (temp != NULL) {
            if (curr->data == temp->data) {
                isRemoved = true;
                Node* nodeToRemove = curr;
                curr = curr->next;
                if (nodeToRemove == head) {
                    head = curr;
                } else {
                    prev->next = curr->next;
                }               
                nodeToRemove->next = NULL;
                delete nodeToRemove;
                break;
            }
            temp = temp->next;
        }
        if (!(isRemoved)) {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

