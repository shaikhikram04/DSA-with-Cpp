// problem link : https://www.codingninjas.com/codestudio/problems/reverse-list-in-k-groups_983644?leftPanelTab=1&campaign=Lovebabbar_codestudio_26thjan&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar_codestudio_26thjan


#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* head) {
    while (head == NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

Node* kReverse(Node* head, int k) {
    // base case
    if (head == NULL){
        return head;
    }
    Node* prev = NULL;
    Node* curr = head;
    int cnt = 1;
    
    // reversing first k node
    while (cnt <= k && curr != NULL) {
        Node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        cnt++;
    }
    // joining other reversed node to the first k node 
    head->next = kReverse(curr, k);
    
    return prev;
}