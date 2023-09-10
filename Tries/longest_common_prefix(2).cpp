
// T.C -> O(M*N)
// S.C -> O(M*N)


#include <bits/stdc++.h>
using namespace std;


class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    int childCount;

    TrieNode(char ch) {
        this->data = ch;
        
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }

        isTerminal = false;
        childCount = 0;
    }
};

class Trie {

    void insertUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }
        
        int index = word[0] - 'a';
        
        if (root->children[index] == NULL) {
            root->children[index] = new TrieNode(word[0]);
            root->childCount++;
        }
        
        insertUtil(root->children[index], word.substr(1));
    }


public:
    
    TrieNode* root;
    
    Trie() {
        root = new TrieNode('\0');
    }

    void insert(vector<string> &arr, int n) {
        for (int i = 0; i < n; i++) {
            insertUtil(root, arr[i]);
        }
    }

    string LCP(string firstWord) {
        TrieNode* curr = root;
        
        string ans = "";
        for (int i = 0; i < firstWord.length(); i++) {
            
            char ch = firstWord[i];
            
            if (curr->childCount == 1) {
                ans.push_back(ch);

                int index = ch - 'a';
                curr = curr->children[index];
            }
            else {
                break;
            }   

            if (curr->isTerminal) {
                break;
            }
        }
        
        return ans;
    }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie* t = new Trie();  

    t->insert(arr, n);

    return t->LCP(arr[0]);
}


