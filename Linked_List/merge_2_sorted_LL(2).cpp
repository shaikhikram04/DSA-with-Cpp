#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int dta){
        data = dta;
    }
};

Node* solve (Node* &first, Node* &second) {
    Node* curr1 = first;
    Node* next1 = curr1->next;
    Node* curr2 = second;

    while (next1 != NULL && curr2 != NULL) {
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data)) {
            Node* temp = curr2->next;
            curr1->next = curr2;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = temp;
        } else {
            curr1 = next1;
            next1 = next1->next;
            if (next1 == NULL) {
                curr1->next = curr2;
            }
        }
    }
    return first;
}

Node* sortTwoLists(Node* first, Node* second) {
    if (first == NULL)
        return second;
    if (second == NULL)
        return first;

    if (first->data < second->data) {
        return solve(first, second);
    } else {
        return solve(second, first);
    }
}