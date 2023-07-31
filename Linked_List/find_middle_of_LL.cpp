// problem link : https://www.codingninjas.com/codestudio/problems/middle-of-linked-list_973250?source=youtube&campaign=Lovebabbarcodestudio_24thJan&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio_24thJan&leftPanelTab=1

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

Node *findMiddle(Node *head) {
    Node* first = head;
    Node* second = head;

    while (second != NULL && second->next != NULL) {
        first = first->next;
        second = second->next->next;
    }
    return first;
}