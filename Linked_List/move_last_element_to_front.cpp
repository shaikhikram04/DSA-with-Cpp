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



class Solution{
public:
    Node *moveToFront(Node *head){
        if (head->next == NULL)
            return head;
            
        Node* curr = head->next;
        Node* prev = head;
        while (curr->next != NULL) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next = head;
        head = curr;
        
        return head;
    }
};