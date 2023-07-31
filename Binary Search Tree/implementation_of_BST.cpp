#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void insertIntoBST(Node* &root, int data) {
    // base case
    if (root == NULL) {
        root = new Node(data);
        return;
    }

    if (data < root->data) {
        insertIntoBST(root->left, data);
    } else {
        insertIntoBST(root->right, data);
    }
}

void takeInput(Node* &root) {
    int data;
    cin >> data;

    while (data != -1) {
        insertIntoBST(root, data);
        cin >> data;
    }

    cout << "\nBST created" << endl;
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            cout << endl;
            if (!q.empty()) 
                q.push(NULL);
        }
        else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}

int main() {

    Node* root = NULL;

    // 8 3 10 14 1 6 7 4 13 -1

    cout << "Enter data for creating BST" << endl;
    takeInput(root);

    cout << "\nLevel order traversal" << endl;
    levelOrderTraversal(root);

    return 0;
}