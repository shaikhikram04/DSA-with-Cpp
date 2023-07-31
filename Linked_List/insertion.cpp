#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    // the pointer is point to the next node therefore it is node type
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// insert data in a linked list at the front
void insertAtHead(Node *&head, int dta)
{
    // creating new node
    Node *temp = new Node(dta);
    temp->next = head;
    head = temp;
}

// inserting data at the back of linked list
void insertAtTail(Node *&tail, int dta)
{
    // creating new node
    Node *temp = new Node(dta);
    tail->next = temp;
    tail = temp;
}

// insert at middle(between head to tail) of linked list
void insertAtPosition(Node *&head, Node* &tail, int position, int dta)
{
    // insert at start position
    if (position == 1)
    {
        insertAtHead(head, dta);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    // traverse to reached at position - 1
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at last position
    if (temp -> next == NULL){
        insertAtTail(tail,dta);
        return;
    }

    // creating new node to insert a data
    Node *nodeToInsert = new Node(dta);

    // updating the address of position-1 node and nodeToInsert node
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

// printing linked list
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // crreating new node n1
    Node *n1 = new Node(10);
    // cout << n1->data << endl;
    // cout << n1->next << endl;

    // head pointed to node n1
    Node *head = n1;
    Node *tail = n1;
    print(head);

    // insert 12 at front and print the linked list
    insertAtHead(head, 12);
    print(head);

    insertAtHead(head, 42);
    print(head);
    cout << endl;

    // inserting 20 at the back
    insertAtTail(tail, 20);
    print(head);

    insertAtTail(tail, 23);
    print(head);

    insertAtPosition(head, tail, 6, 55);
    print(head);

    return 0;
}