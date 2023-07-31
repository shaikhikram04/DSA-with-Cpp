// problem link : https://www.codingninjas.com/codestudio/problems/circularly-linked_1070232?source=youtube&campaign=Lovebabbar_codestudio_26thjan&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar_codestudio_26thjan&leftPanelTab=0

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

bool isCircular(Node* head){
    if (head == NULL)
        return true;
    Node* temp = head;
    while(temp != NULL && temp->data != 0) {
        if(temp->next == head)
            return true;
        temp->data = 0;
        temp = temp->next;
    }
    return false;
}
