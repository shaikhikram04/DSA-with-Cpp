#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(Node* root) {
    int data;
    cout << "Enter a data : ";
    cin >> data;
    if (data == -1) {
        return NULL;
    }

    root =new Node(data);
    cout << "For inserting left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "For inserting right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void inorder (Node* root) {
    stack<Node*> s;
    Node* curr = root;
    while (!s.empty() || curr != NULL) {
        while (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }
        cout << s.top()->data <<" ";
        curr = s.top()->right;
        s.pop();
    }
}

void preorder(Node* root) {
    stack<Node*> s;
    Node* curr = root;

    while (!s.empty() || curr != NULL) {
        while (curr != NULL) {
            cout << curr->data << " ";
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        curr = curr->right;
    }
}

void postorder(Node* root) {
    stack<Node*> s;
    Node* curr = root;
    unordered_map<Node*, int> isLRTraversed;
    while (!s.empty() || curr != NULL) {
        while (curr != NULL) {
            s.push(curr);
            isLRTraversed[curr] = 1;
            curr = curr->left;
        }
        curr = s.top();
        if (isLRTraversed[curr] == 2) {
            cout << curr->data << " ";
            s.pop();
            curr = NULL;
        } else {
            isLRTraversed[curr]++;
            curr = curr->right;
        }
    }
}

int main () {
    Node* root = NULL;

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    cout << "\n\n Inorder traversal" << endl;
    inorder(root);

    cout << "\n\n Preorder traversal" << endl;
    preorder(root);

    cout << "\n\n Postorder traversal" << endl;
    postorder(root);

    return 0;
}