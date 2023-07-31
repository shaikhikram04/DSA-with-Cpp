// https://www.codingninjas.com/studio/problems/smallest-range-from-k-sorted-list_1069356?leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std; 

class node {
public:
    int data;
    int row;
    int col;

    node(int data, int rowIndex, int colIndex) {
        this->data = data;
        row = rowIndex;
        col = colIndex;
    }
};

class compare {
public:
    bool operator()(node* a, node* b) {
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n) {

    int range = INT_MAX;
    
    priority_queue<node*, vector<node*>, compare> minHeap;
    int maxi = 0;

    for (int i = 0; i < k; i++) {
        node* temp = new node(a[i][0], i, 0);
        minHeap.push(temp);
        maxi = max(maxi, temp->data);
    }

    while (minHeap.size() == k) {
        node* top = minHeap.top();
        range = min(range, (maxi-(top->data)+1));
        minHeap.pop();

        int i = top->row;
        int j = top->col;

        if (j+1 < n) {
            node* next = new node(a[i][j+1], i, j+1);
            minHeap.push(next);
            maxi = max(maxi, next->data);
        }
    }

    return range;
}