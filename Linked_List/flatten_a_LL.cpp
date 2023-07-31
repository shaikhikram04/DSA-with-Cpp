#include <iostream>

class Node
{
public:
    int data;
    Node *next;
    Node *child;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
    }
};

Node *mergeLL(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return head2;
    else if (head2 == NULL)
        return head1;
    Node *root = (head1->data > head2->data) ? (head2) : (head1);
    Node *prev = root;
    Node *first = root->child;
    Node *second = (root == head1) ? (head2) : (head1);
    while (first != NULL && second != NULL)
    {
        if (first->data < second->data)
        {
            prev->child = first;
            prev = first;
            first = first->child;
        }
        else
        {
            prev->child = second;
            prev = second;
            second = second->child;
        }
    }
    if (first != NULL)
    {
        prev->child = first;
    }
    else if (second != NULL)
    {
        prev->child = second;
    }
    return root;
}

Node *flattenLinkedList(Node *head)
{
    // Recursive Approach
    // base case
    if (head == NULL || head->next == NULL)
        return head;

    Node *root = head->next;
    head->next = NULL;
    root = flattenLinkedList(root);
    head = mergeLL(head, root);
    return head;
}