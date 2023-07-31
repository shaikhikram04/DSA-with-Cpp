// problem link : https://www.codingninjas.com/codestudio/problems/interview-shuriken-42-detect-and-remove-loop_241049?leftPanelTab=0%3Fsource%3Dyoutube&campaign=YouTube_codestudio_lovebabbar28thjan&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_codestudio_lovebabbar28thjan

// using map

#include <iostream>
#include <map>
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

Node* detectLoop(Node *head){
    // return NULL when empty list
    if (head == NULL) 
        return NULL;

    // declare map that contain pointer as a key and bool as a value
    map<Node*, bool> visited;
    while (head != NULL) {
        // mapped head to true
        visited[head] = true;
        // if we visit again at the node then return last node
        if (visited[head->next] == true)
            return head;

        // check for next node
        head = head->next;
    }
    // return NULL when loop is absent
    return NULL;
}

Node *removeLoop(Node *head)
{
    Node* last = detectLoop(head);
    // if last = NULL that means loop is absent
    if (last == NULL)
        return head;
    // removing loop 
    last->next = NULL;
    return head;
}
