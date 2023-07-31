#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class node {
public: 
    int data;
    node* left;
    node* right;

    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* buildTree(node* root) {
    int data;
    cout << "Enter the data : ";
    cin >> data;

    if (data == -1) {
        return NULL;
    }
    
    root = new node(data);

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

// level order traversal
void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            // previous level has been traversed
            cout << endl;
            if (! q.empty()) {
                // queue still have some child node
                q.push(NULL); // next level has been inserted in a Q
            }
        }
        else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

// reverse level order traversal

void reverseLevelOrderTraversal(node* root) {
    stack<node*> s;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    
    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
        s.push(temp);
        if (temp == NULL) {
            if (!q.empty())
                q.push(NULL);
        }
        else {
            if (temp->right) {
                q.push(temp->right);
            }
            if (temp->left) {
                q.push(temp->left);
            }
        }
    }
    
    while (!s.empty()) {

        node* curr = s.top();
        s.pop();
        
        if (curr == NULL) {
            cout << endl;
        }
        else {
            cout << curr->data << " " ;
        }
    }
}

int main() {
    node* root = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // creation of binary tree
    root = buildTree(root);

    // printing binary tree using level order traverse
    cout << "\n\nprinting in level order traversal" << endl;
    levelOrderTraversal(root);

    cout  << "\n\n printing in reverse level order traversal" << endl;
    reverseLevelOrderTraversal(root);

    return 0;
}
