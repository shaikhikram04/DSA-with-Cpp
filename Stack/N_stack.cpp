// https://www.codingninjas.com/codestudio/problems/n-stacks-in-an-array_1164271?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&campaign=Lovebabbarcodestudio11thfeb

#include <bits/stdc++.h> 
class NStack
{
    int *arr;
    int *top;
    int *next;
    int freeSpot;
    int size;

public:
    // Initialize your data structure.

    NStack(int N, int S)
    {
        arr = new int[S];
        top = new int[N];
        next = new int[S];
        freeSpot = 0;

        for (int i = 0; i < S - 1; i++) {
            next[i] = i + 1;
        }
        next[S-1] = -1;

        for (int i = 0; i < N; i++) {
            top[i] = -1;
        }
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // check for overFlow
        if (freeSpot == -1) {
            return false;
        }
        // find index
        int index = freeSpot;

        // update freeSpot
        freeSpot = next[index];

        // insert in array
        arr[index] = x;

        // update next
        next[index] = top[m-1];
        
        // update top
        top[m-1] = index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // check for underflow
        if (top[m-1] == -1) {
            return -1;
        }
        // store freespot
        int temp = freeSpot;

        // update freespot
        freeSpot = top[m-1];

        // update top
        top[m-1] = next[freeSpot];

        // update next
        next[freeSpot] = temp;

        return arr[freeSpot];
    }
};  