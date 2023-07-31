// problem link : https://www.codingninjas.com/codestudio/problems/unique-sorted-list_2420283?leftPanelTab=0&campaign=YouTube_Lovebabbar29thJan&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_Lovebabbar29thJan

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) 
    {
        this->data = data;
        this->next = NULL;
    }
};

Node * uniqueSortedList(Node * head) {
    if (head == NULL)
        return head;

    Node* prev = head;
    Node* temp = head->next;
    while (temp != NULL) {
        if (prev->data == temp->data) {
            Node* nodeToRemove = temp;
            temp = temp->next;
            nodeToRemove->next = NULL;
            delete nodeToRemove;
            prev->next = temp;
            continue;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}