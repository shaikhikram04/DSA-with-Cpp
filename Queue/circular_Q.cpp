// https://www.codingninjas.com/codestudio/problems/circular-queue_1170058?leftPanelTab=0%3Fsource%3Dyoutube&campaign=LoveBabbar_Codestudio

#include <bits/stdc++.h> 
class CircularQueue{
    int *arr;
    int front;
    int rear;
    int size;

    public:
    // Initialize your data structure.
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        front = -1 ;
        rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // if array is full
        if ((front == 0 && rear == size - 1) || rear == (front - 1) % (size - 1)) { 
            return false;
        }
        // insert first element
        if (rear == -1) {
            rear = front = 0;
        }
        // rear reach at last index then perform cycle
        else if (rear == size -1 && front != 0) {
            rear = 0;
        } 
        // normal part
        else {
            rear++;
        }
        // insert value
        arr[rear] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // array is empty
        if (front == -1 ) {
            return -1;
        }
        // store front value of array
        int ans = arr[front];
        // for remaining 1 element only
        if (rear == front) {
            rear = front = -1;
        }
        // front is reached at end
        else if (front == size - 1) {
            front = 0;
        }
        // normal part
        else {
            front++;
        }
        return ans;
    }
};