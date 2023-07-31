// problem link : https://www.codingninjas.com/codestudio/problems/valid-parenthesis_795104?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio
#include <iostream>
#include <stack>
using namespace std;

bool isValidParenthesis(string expression)
{
    stack<char> s;
    for (int i = 0; i < expression.size(); i++) {
        char ch = expression[i];
        if (ch == '{' || ch == '(' || ch == '[')
            s.push(ch);
        else 
            if (!s.empty()) {
                char top = s.top();
                if ((ch == '}' && top == '{') || (ch == ')' && top == '(') || (ch == ']' && top == '['))
                    s.pop();
                else
                    return false;
            }
            else 
                return false;
    }
    return s.empty();
}