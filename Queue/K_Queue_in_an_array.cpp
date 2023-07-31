
#include <bits/stdc++.h>

class NQueue{
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freeSpot;

public:
    // Initialize your data structure.
    NQueue(int n, int s){
        arr = new int[s];
        front = new int[n];
        rear = new int[n];
        next = new int[s];
        freeSpot = 0;

        for (int i = 0; i < n; i++) {
            front[i] = rear[i] = -1;
        }
        for (int i = 0; i < s - 1; i++) {
            next[i] = i + 1;
        }
        next[s-1] = -1;    
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){
        // check for overflow
        if (freeSpot == -1) {
            return false;
        }

        // find index
        int index = freeSpot;

        // update freeSpot
        freeSpot = next[index];

        // insert value
        arr[index] = x;

        // insert first value
        if (front[m-1] == -1) {
            front[m-1] = index;
        } else {
            next[rear[m-1]] = index;
        }
        next[index] = -1;

        rear[m-1] = index;

        return true;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
        // check for underflow
        if (front[m-1] == -1) {
            return -1;
        }
        // find index
        int index = front[m-1];

        // update front
        front[m-1] = next[index];
        // for single element
        if (front[m-1] == -1) {
            rear[m-1] = -1;
        }
        // update next
        next[index] = freeSpot;

        // update freeSpot
        freeSpot = index;

        return arr[index];
    }

    bool empty(int m) {
        return (front[m-1] == -1);
    }

    int Front(int m) {
        if (empty(m)) {
            return -1;
        }
        return arr[front[m-1]];
    }

    int back(int m) {
        if (empty(m)) {
            return -1;
        }
        return arr[rear[m-1]];
    }
};