// problem link : https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int dta) {
        data = dta;
        next = NULL;
    }
};

bool isPalindrome(Node *head)
{
    vector<int> LL;
    Node* curr = head;
    while (curr != NULL) {
        LL.push_back(curr->data);
        curr = curr->next;
    }
    int i = 0, j = LL.size() - 1;
    while (i < j) {
        if (LL[i] == LL[j]) {
            i++;
            j--;
        } else {
            return false;
        }
    }
    return true;
}