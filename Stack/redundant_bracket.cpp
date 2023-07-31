// problem link : https://www.codingninjas.com/codestudio/problems/redundant-brackets_975473?leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio

#include <bits/stdc++.h> 
using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        }
        else if (ch == ')') {

            bool isRedundant = true;
            while (st.top() != '(') {
                char top = st.top();
                isRedundant = false;
                st.pop();
            }
            if (isRedundant) {
                return true;
            }
            st.pop();
        }
    }
    return false;
}

int main() {
    string s = "(a+c*b)+(c)";
    if(findRedundantBrackets(s)) {
        cout << "yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}