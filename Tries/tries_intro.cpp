#include <iostream>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++)  {
            children[i] = NULL;
        }

        isTerminal = false;
    }
};


class Trie {

    void insertUtil(TrieNode* root, string word) {
        // base case 
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        // assumption, words will be in CAPS
        int index = word[0] - 'A';
        TrieNode* child;

        // present
        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        // absent
        else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursive call
        insertUtil(child, word.substr(1));
    }

    bool searchUtil(TrieNode* root, string word) {
        // base case
        if (word.length() == 0)
            return root->isTerminal;

        int index = word[0] - 'A';

        if (root->children[index] != NULL) {
            return searchUtil(root->children[index], word.substr(1));
        }
        else { 
            return false;
        }
    }

    
    void removeUtil(TrieNode* root, string word) {
        // base case
        if (word.length() == 0) {
            root->isTerminal = false;
            return ;
        }

        int index = word[0] - 'A';
        if (root->children[index] != NULL) {
            TrieNode* child = root->children[index];
            removeUtil(child, word.substr(1));

            bool isAnyChild = false;
            for (int i = 0; i < 26; i++) {
                if (child->children[i] != NULL) {
                    isAnyChild = true;
                    break; 
                }
            }

            if (!isAnyChild && !child->isTerminal) {
                delete child;
            }
        }
        else {
            return;
        }
    }

public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    // insertion
    void insertWord(string word) {
        insertUtil(root, word);
        cout << word << " inserted" << endl;
    }

    bool searchWord(string word) {
        return searchUtil(root, word);
    }

    void removeWord(string word) {
        removeUtil(root, word);
    }
};


int main() {

    Trie t;

    t.insertWord("ANIMAL");
    t.insertWord("APPLE");
    t.insertWord("DON");
    t.insertWord("DONKEY");

    cout << "APPLE present -> " << t.searchWord("APPLE") << endl;
    cout << "ANIMAL present -> " << t.searchWord("ANIMAL") << endl;
    cout << "APP present -> " << t.searchWord("APP") << endl;

    cout << t.root->data << endl;

    t.removeWord("APPLE");
    t.removeWord("DONKEY");
    
    cout << "APPLE present -> " << t.searchWord("APPLE") << endl;
    cout << "DONKEY present -> " << t.searchWord("DONKEY") << endl;
    cout << "DON present -> " << t.searchWord("DON") << endl;


    return 0;
}