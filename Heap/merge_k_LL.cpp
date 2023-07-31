// https://www.codingninjas.com/studio/problems/merge-k-sorted-lists_992772?leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std; 

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        next = NULL;
        this->data = data;
    }

    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};


#include <queue>

class compare {
public:
    bool operator()(Node* a, Node*b) {
        return a->data > b->data;
    }
};

Node* mergeKLists(vector<Node*> &listArray)
{
    int k = listArray.size();
    // k == 0
    if (!k) 
        return NULL;
    
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    for (int i = 0; i < k; i++) {
        if (listArray[i])
            minHeap.push(listArray[i]);
    }

    Node* head = NULL;
    Node* tail = NULL;

    while (!minHeap.empty()) {
        Node* temp = minHeap.top();
        minHeap.pop();

        if (temp->next)
            minHeap.push(temp->next);
        
        if (head == NULL) 
            head = tail = temp;
        
        else {
            tail->next = temp;
            tail = temp;
        }
    }

    return head;
}







