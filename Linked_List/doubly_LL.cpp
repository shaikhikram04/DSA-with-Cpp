#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    // constructor
    Node(int dta)
    {
        this->data = dta;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node()
    {
        if (this->next != NULL || this->prev != NULL)
        {
            this->next == NULL;
            this->prev == NULL;
        }
    }
};

// traverse and print linked list
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

// give length of linked list
int getLength(Node *&head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node *&head, Node *&tail, int dta)
{
    if (head == NULL)
    {
        Node *temp = new Node(dta);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(dta);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

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

void insertAtPosition(Node *&head, Node *&tail, int position, int dta)
{
    // inserting at head
    if (position == 1)
    {
        insertAtHead(head, tail, dta);
        return;
    }
    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at tail
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, dta);
        return;
    }

    Node *nodeToInsert = new Node(dta);

    // updating inserted node
    nodeToInsert->next = temp->next;
    nodeToInsert->prev = temp;

    // updating previous and next node to the inserted node
    temp->next = nodeToInsert;
    temp->next->prev = nodeToInsert;
}

void deleteHead(Node *&head, int position)
{
    Node *temp = head;
    temp->next->prev = NULL;
    head = head->next;

    delete temp;
}

void deleteNode(Node *&head, Node *&tail, int position)
{
    if (position == 1)
    {
        deleteHead(head, position);
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
        goto last;
    }
    nodeToDelete->next->prev = temp;
last:
    temp->next = nodeToDelete->next;

    delete nodeToDelete;
}

int main()
{
    Node *node1 = new Node(7);
    Node *head = node1;
    Node *tail = node1;
    cout << endl;

    printLL(head);
    // cout << "length : " << getLength(head) << endl;

    insertAtHead(head, tail, 27);
    printLL(head);
    // cout << "length : " << getLength(head) << endl;

    insertAtTail(head, tail, 45);
    printLL(head);

    insertAtPosition(head, tail, 3, 10);
    printLL(head);

    insertAtPosition(head, tail, 3, 71);
    printLL(head);

    deleteNode(head, tail, 5);
    printLL(head);

    printLL(head);
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;

    cout << endl;
    return 0;
}