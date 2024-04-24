//? https://www.geeksforgeeks.org/problems/huffman-encoding3345/1

//! T.C -> O(n*log(n))
//! S.C -> O(n)

//* priority queue, greedy

#include <bits/stdc++.h>
using namespace std;

//* Definition of a node in a binary tree
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr; 
    }
};

//* Functor class for comparing nodes to create a min-heap
class compare {
    public:
    //* Overloaded () operator to compare nodes based on their data values
    bool operator()(Node* a, Node* b){
        return a->data > b->data;  //* Comparison for min-heap: a > b
    }
};

class Solution
{
    //* Pre-order traversal for generating Huffman codes
    void preTraverse(Node* root, vector<string>& ans, string temp) {
        //* If the current node is a leaf node, 
        //* push the Huffman code stored in 'temp' to the result and return
        if(root->left == nullptr && root->right == nullptr) {
            ans.push_back(temp);
            return;
        }
        
        //* Recursively traverse the left subtree, appending '0' to the Huffman code
        preTraverse(root->left, ans, temp+"0");
        //* Recursively traverse the right subtree, appending '1' to the Huffman code
        preTraverse(root->right, ans, temp+"1");
    }
    
	public:
	vector<string> huffmanCodes(string S, vector<int> f, int N)
	{
        //* Creating a min-heap of type Node for the characters and their frequencies
	    priority_queue<Node*, vector<Node*>, compare> minHeap;
	    
        //* Inserting each character frequency as a node into the min-heap
	    for (int i = 0; i < N; i++) {
	        Node* temp = new Node(f[i]);
	        minHeap.push(temp);
	    }
	    
        //* Building the Huffman tree by combining the nodes until only one node remains in the heap
	    while(minHeap.size() > 1) {
            //* Extracting the node with the minimum frequency as the left node
	        Node* left = minHeap.top();
	        minHeap.pop();
	        
            //* Extracting the node with the next minimum frequency as the right node
	        Node* right = minHeap.top();
	        minHeap.pop();
	        
            //* Creating a new node representing the combined frequency of left and right nodes
            //* Assigning left and right nodes as children of the new node
	        Node* sum = new Node(left->data + right->data);
	        sum->left = left;
	        sum->right = right;
	        
            //* Adding the new node back to the min-heap
	        minHeap.push(sum);
	    }

        //* Creating a vector to store the generated Huffman codes
	    vector<string> ans;
	    string temp = "";   //* Temporary string to store the Huffman code during traversal

        //* The remaining node in the min-heap is the root of the Huffman tree
	    Node* root = minHeap.top();
        //* Traversing the Huffman tree in pre-order to generate Huffman codes
	    preTraverse(root, ans, temp);
	    
        //* Returning the vector of generated Huffman codes
	    return ans;
	}
};
