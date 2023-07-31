// https://www.codingninjas.com/codestudio/problems/queue-using-array-or-singly-linked-list_2099908?leftPanelTab=0%3Fsource%3Dyoutube&campaign=LoveBabbar_Codestudio

#include <bits/stdc++.h> 
class Queue {
    int *arr;
    int first;
    int rear;
    int size;
public:
    Queue() {
        size = 5000;
        arr = new int[size];
        first = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return (rear == first);
    }

    void enqueue(int data) {
        if (rear == size && arr[0] == -1) {
            rear = 0;
        }
        arr[rear] = data;
        rear++;
    }

    int dequeue() {
        if (rear == first) {
            return -1;
        }
        int ans = arr[first];
        arr[first] = -1;
        first++;
        if (first == rear) {
            first = 0;
            rear = 0;
        }
        return ans;
    }

    int front() {
        if (first == rear) {
            return -1;
        }
        return arr[first];
    }
};