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

Node* buildTree (Node* root) {
    int d;
    cout << "Enter a data : " ;
    cin >> d;

    if (d == -1) {
        return NULL;
    }

    root = new Node(d);

    cout << "For inserting left of " << d << endl;
    root->left = buildTree(root->left);
    cout << "For inserting right of " << d << endl;
    root->right = buildTree(root->right);

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

void inOrder(Node* root) {
    // base case
    if (root == NULL) {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(Node* root) {
    // base case
    if (root == NULL) {
        return;
    }
    
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = NULL;

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // creating binary tree
    root = buildTree(root);

    // level order traversal
    cout << "\n\n Level order traversal" << endl;
    levelOrderTraversal(root);

    // inorder traversal
    cout << "\n\n Inorder traversal" << endl;
    inOrder(root);

    // preorder traversal
    cout << "\n\n Preorder traversal" << endl;
    preOrder(root);

    // postorder traversal
    cout << "\n\n Postorder traversal" << endl;
    postOrder(root);

    return 0;
}