#include <bits/stdc++.h> 
using namespace std;

class TreeNode{

    public :
        int data;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
        if (left){
        delete left;
        }

        if (right){
        delete right;
        }
    }   
};



void convertIntoSortedDLL(TreeNode* root, TreeNode* &head) {
    if (root == NULL) {
        return;
    }
    
    convertIntoSortedDLL(root->right, head);
    
    root->right = head;
    if (head)
        head->left = root;

    head = root;
    
    convertIntoSortedDLL(root->left, head);
}

TreeNode* merge2LL(TreeNode* head1, TreeNode* head2) {

    TreeNode* head = NULL;
    TreeNode* tail = head;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            if (head == NULL) {
                head = tail = head1;
            }
            else {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
            }
            head1 = head1->right;
        }
        else {
            if (head == NULL) {
                head = tail = head2;
            }
            else {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
            }
            head2 = head2->right;
        }
    }
    while (head1 != NULL) {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while (head2 != NULL) {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

int countNode(TreeNode* head) {
    int cnt = 0;
    TreeNode* temp = head;
    while (temp != NULL) {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

TreeNode* sortedLLToBST(TreeNode* &head, int n){
    // base case
    if (n <= 0 || head == NULL) {
        return NULL;
    }
    
    TreeNode* left = sortedLLToBST(head, n/2);

    TreeNode* root = head;
    root->left = left;

    head = head->right;

    root->right = sortedLLToBST(head, n-n/2-1);

    return root;
}

TreeNode* mergeBST(TreeNode *root1, TreeNode *root2){
    // step 1 : convert BST into sorted LL
    TreeNode* head1 = NULL;
    TreeNode* head2 = NULL;

    convertIntoSortedDLL(root1, head1);
    convertIntoSortedDLL(root2, head2);

    // step 2 : merge 2 sorted LL
    TreeNode* head = merge2LL(head1, head2);

    // step 3 : convert sorted LL into balanced BST
    return sortedLLToBST(head, countNode(head));    
}
