// problem link : https://www.codingninjas.com/codestudio/problems/reverse-the-singly-linked-list_799897?source=youtube&campaign=Lovebabbarcodestudio_24thJan&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio_24thJan&leftPanelTab=1

#include <bits/stdc++.h>

// using loop

class LinkedListNode
{
public:
    int data;
    LinkedListNode* next;
    LinkedListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

LinkedListNode *reverseLinkedList(LinkedListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    LinkedListNode *prev = NULL;
    LinkedListNode *curr = head;

    while (curr != NULL)
    {
        LinkedListNode *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}