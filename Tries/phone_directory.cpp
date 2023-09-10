// https://www.codingninjas.com/studio/problems/implement-a-phone-directory_1062666?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0



// T.C -> O(M*N)
// S.C -> O(M*N)


#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* child[26];
    bool isTerminal;

    TrieNode (char ch) {
        data = ch;

        for (int i = 0; i < 26; i++) {
            child[26] = NULL;
        }

        isTerminal = false;
    }
};

void insert(TrieNode* root, string word) {
    // base case
    if (word.size() == 0) {
        root->isTerminal = true;
        return;
    }

    int index = word[0] - 'a';

    if (root->child[index] == NULL) {
        root->child[index] = new TrieNode(word[0]);
    }

    insert(root->child[index], word.substr(1));
}

void storeAllWords(TrieNode* root, string prefix, vector<string> &ans) {
    if (root->isTerminal) {
        ans.push_back(prefix);
    }

    for (int i = 0; i < 26; i++) {
        if (root->child[i] != NULL) {
            prefix.push_back(root->child[i]->data);
            storeAllWords(root->child[i], prefix, ans);
            prefix.pop_back();
        }
    }
}

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    TrieNode* root = new TrieNode('\0');

    for (int i = 0; i < contactList.size(); i++) {
        insert(root, contactList[i]);
    }

    vector<vector<string>> ans;

    TrieNode* curr = root;

    string prefix = "";
    for (int i = 0; i < queryStr.size(); i++) {
        prefix.push_back(queryStr[i]);

        int index = queryStr[i] - 'a';
        
        if (curr->child[index] != NULL) {
            curr = curr->child[index];
        } else {
            return ans;
        }
 
        vector<string> temp;
        storeAllWords(curr, prefix, temp);

        ans.push_back(temp);
    }

    return ans;
}