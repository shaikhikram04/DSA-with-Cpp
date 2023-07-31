#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int dta){
        data = dta;
        next = NULL;
    }
};

Node* sortList(Node *head)
{
    int zero = 0;
    int one = 0;
    int two = 0;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == 0) 
            zero++;
        else if (temp->data == 1) 
            one++;
        else if (temp->data == 2)
            two++;
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL) {
        if (zero > 0) {
            temp->data = 0;
            zero--;
        }
        else if (one > 0) {
            temp->data = 1;
            one--;
        }
        else if (two > 0) {
            temp->data = 2;
            two--;
        }
        temp = temp->next;
    }
    return head;
}