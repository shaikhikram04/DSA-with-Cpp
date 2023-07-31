#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int dta)
    {
        this->data = dta;
        this->next = NULL;
    }

    // destructor to momory free
    ~Node()
    {
        if (this->next != NULL)
        {
            this->next = NULL;
        }
    }
    
};

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
void insertAtPosition(Node *&head, Node *&tail, int position, int dta)
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
    if (temp->next == NULL)
    {
        insertAtTail(tail, dta);
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

// detetion of first element
void deleteHead(Node *&head)
{
    Node *temp = head;
    head = head->next;
    delete temp;
}

// deletion of any node
void deleteNode(int position, Node *&head, Node *&tail)
{
    if (position == 1)
    {
        deleteHead(head);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    Node *nodeToDelete = temp->next;
    if (nodeToDelete->next == NULL)
    {
        tail = temp;
    }
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    cout << endl;

    insertAtHead(head, 42);
    insertAtTail(tail, 12);
    insertAtPosition(head, tail, 3, 55);
    print(head);

    deleteNode(2, head, tail);
    cout << "After deletion " << endl;
    print(head);
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;
    cout << endl;
    return 0;
}