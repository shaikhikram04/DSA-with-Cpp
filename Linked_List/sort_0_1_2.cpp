// problem link : https://www.codingninjas.com/codestudio/problems/sort-linked-list-of-0s-1s-2s_1071937?leftPanelTab=1&campaign=YouTube_Lovebabbar31stJan2021&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_Lovebabbar31stJan2021

#include <iostream>
#include <map>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int dta){
        data = dta;
    }
};

Node* sortList(Node *head)
{
    map<int, int> cnt;
    cnt[0] = 0;
    cnt[1] = 0;
    cnt[2] = 0;
    Node* temp = head;
    while (temp != NULL) {
        cnt[temp->data]++;
        temp = temp->next;
    }
    temp = head;
    for (int i = 0; i <= 2; i++) {
        while (cnt[i] > 0) {
            temp->data = i;
            cnt[i]--;
            temp = temp->next;
        }
    }
    return head;
}