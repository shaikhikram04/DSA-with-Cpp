#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int dta)
    {
        data = dta;
        next = NULL;
    }

    ~Node()
    {
        if (this->next != NULL)
        {
            this->next = NULL;
        }
    }
};

void insertNode(Node *&tail, int element, int dta)
{
    // assuming element is present in the linked list

    // if LL is empty
    if (tail == NULL)
    {
        Node *node1 = new Node(dta);
        node1->next = node1;
        tail = node1;
        return;
    }

    Node *temp = new Node(dta);
    Node *current = tail->next;

    // traverse to reach at element
    while (current->data != element)
    {
        current = current->next;
    }

    temp->next = current->next;
    current->next = temp;
}

void print(Node *&tail)
{
    // empty list
    if (tail == NULL)
    {
        cout << "list is empty" << endl;
        return;
    }
    // non-empty list
    Node *temp = tail->next;
    // printing whole linked list
    while (temp != tail)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << tail->data << endl;
}

void deleteNode(Node *&tail, int value)
{
    // empty LL
    if (tail == NULL)
    {
        cout << "list is empty, please check again." << endl;
        return;
    }
    // non empty linked list
    Node *prev = tail;
    Node *curr = tail->next;
    while (curr->data != value)
    {
        prev = curr;
        curr = curr->next;
    }
    // deleting tail node
    if (curr == tail)
    {
        tail = prev;
    }
    // deleting node from 1 node, then LL become empty
    if (curr == prev)
    {
        tail = NULL;
    }
    prev->next = curr->next;
    delete curr;
}

int main()
{
    /*
    Node *node1 = new Node(3);
    node1->next = node1;
    */
    Node *tail = NULL;

    // print(tail);

    insertNode(tail, 3, 10);
    print(tail);

    insertNode(tail, 10, 43);
    print(tail);

    insertNode(tail, 10, 19);
    print(tail);

    insertNode(tail, 10, 20);
    print(tail);

    insertNode(tail, 19, 57);
    print(tail);

    insertNode(tail, 20, 8);
    print(tail);

    insertNode(tail, 43, 87);
    print(tail);

    deleteNode(tail, 8);
    print(tail);

    deleteNode(tail, 57);
    print(tail);

    deleteNode(tail, 10);
    print(tail);

    return 0;
}