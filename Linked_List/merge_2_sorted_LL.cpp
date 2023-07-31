// problem link : https://www.codingninjas.com/codestudio/problems/merge-two-sorted-linked-lists_800332?leftPanelTab=1&campaign=YouTube_Lovebabbar31stJan2021&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_Lovebabbar31stJan2021

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

Node* sortTwoLists(Node* first, Node* second) {
    // if second list is empty then return first list
    if (second == NULL)
        return first;
    // if first list is empty then return second list
    if (first == NULL) 
        return second;
    Node* head = NULL;
    // assign head to those LL head which first data is small
    if (first->data < second->data){
        head = first;
        first = first->next;
    } else {
        head = second;
        second = second->next;
    }
    // travarse LL and merging both LL is assending order   
    Node* curr = head;
    while (first != NULL && second != NULL) {
        if (first->data < second->data) {
            curr->next = first;
            first = first->next;
        } else {
            curr->next = second;
            second = second->next;
        }
        curr = curr->next;
    }
    while (first != NULL) {
        curr->next = first;
        first = first->next;
        curr = curr->next;
    }
    while (second != NULL) {
        curr->next = second;
        second = second->next;
        curr = curr->next;
    }
    return head;
}