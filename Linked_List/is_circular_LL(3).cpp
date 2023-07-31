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

bool isCircular(Node* head){
    if (head == NULL) {
        return true;
    }
    map<Node*,bool> visited;
    Node* temp = head;
    while (temp != NULL) {
        if (visited[temp] == true) 
            return false;
    
        if(temp->next == head)
            return true;
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}