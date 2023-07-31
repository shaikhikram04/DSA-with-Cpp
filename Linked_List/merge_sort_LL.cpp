#include <iostream>
using namespace std;

class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

node* findMid(node* head) {
    node* slow = head;
    node* fast = head->next;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* solve(node* left, node* right) {
    node* curr1 = left;
    node* next1 = curr1->next;
    node* curr2 = right;

    while (next1 != NULL && curr2 != NULL) {
        if (curr2->data >= curr1->data && curr2->data < next1->data) {
            node* next2 = curr2->next;
            curr1->next = curr2;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        } else {
            curr1 = next1;
            next1 = next1->next;
        }
    }
    if (next1 == NULL) {
        curr1->next = curr2;
    }
    return left;
}

node* merge(node* left,node* right) {
    if (left == NULL)
        return right;
    if (right == NULL) 
        return left;

    if (left->data < right->data) {
        return solve(left, right);
    }
    else {
        return solve(right, left);
    }
}

node* mergeSort(node *head) {
    // base case
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // break LL into 2 halves after finding mid
    node* mid = findMid(head);

    node* left = head;
    node* right = mid->next;
    mid->next = NULL;

    // recersive call to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // merge both left and right halves
    node* result = merge(left, right);

    return result;
}