#include <iostream>
#include <queue>
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

Node* buildInLevelOrderForm(Node* root) {
    int data;
    queue <Node*> q;
    cout << "Enter data for root : ";
    cin >> data;
    if (data == -1) {
        return NULL;
    }
    root = new Node(data);
    q.push(root);
    Node* temp;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        cout << "Enter data for left of " << temp->data << " : " ;
        cin >> data;
        if (data != -1) {
            temp->left = new Node(data);
            q.push(temp->left);
        }
        

        cout << "Enter data for right of " << temp->data << " : " ;
        cin >> data;
        if (data != -1) {
            temp->right = new Node(data);
            q.push(temp->right);
        }
        
    }

    return root;
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        Node* temp = q.front();
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

int main() {
    Node* root = NULL;
    root = buildInLevelOrderForm(root);
    cout << "\n\nprinting tree" << endl;
    levelOrderTraversal(root);
    return 0;
}