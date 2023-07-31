// problem link : https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertAtTail(Node *&head, Node *&tail, int dta)
{
    if (tail == NULL)
    {
        Node *temp = new Node(dta);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(dta);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

Node *reverseDoublyLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    while (head != NULL)
    {
        Node *temp = head->next;
        head->next = head->prev;
        head->prev = temp;
        if (head->prev == NULL)
            break;
        head = temp;
    }
    return head;
}

void printLL(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,3);
    insertAtTail(head,tail,4);
    insertAtTail(head,tail,5);
    printLL(head);

    head = reverseDoublyLL(head);
    printLL(head);

    return 0;
}