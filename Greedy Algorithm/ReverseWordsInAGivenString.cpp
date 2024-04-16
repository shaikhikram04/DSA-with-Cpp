//? https://www.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1

//! T.C -> O(n)
//! S.C -> O(n)

//* reverse, greedy

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    //* reversing string
    void reverseStr(string& str) {
        int i = 0, j = str.size()-1;
        while (i < j) {
            swap(str[i++], str[j--]);
        }
    }
    public:
    //! Function to reverse words in a given string.
    string reverseWords(string& S) 
    { 
        //* Store each word temporarily in reverse form
        string word = "";
        //* Store the resultant string
        string ans = "";

        //* Traverse the string from back
        for (int i = S.size()-1; i >= 0; i--) {
            //* If '.' is detected, reverse the word string to make it in the right form  
            //* and add it into the ans string with '.'. Then clear the word string to store the next word.
            if (S[i] == '.') {
                reverseStr(word);
                ans += word + ".";
                word = "";
            }
            //* Otherwise, push characters into the word string, which are stored in reverse form
            else
                word.push_back(S[i]);
        }

        //* After traversing, the first word of the input string is stored in the word string.
        //* So, add it to the ans string after reversing it.
        reverseStr(word);
        ans += word;
        
        //* Return the resultant string
        return ans;
    } 
};