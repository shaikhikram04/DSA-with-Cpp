// problem link : https://www.codingninjas.com/codestudio/problems/remove-duplicates-from-unsorted-linked-list_1069331?source=youtube&campaign=YouTube_Lovebabbar29thJan&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_Lovebabbar29thJan


#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) 
    {
        this->data = data;
        this->next = NULL;
    }
};


Node *removeDuplicates(Node *head)
{
    unordered_map<int, bool> visited;
    Node* prev = NULL; 
    Node* curr = head;
    while (curr != NULL) {
        if (visited[curr->data] == true) {
            Node* nodeToRemove = curr;
            curr = curr->next;
            nodeToRemove->next = NULL;
            delete nodeToRemove;
            prev->next = curr;
        }else {
            visited[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}