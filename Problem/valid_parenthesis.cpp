#include <iostream>
using namespace std;

bool isValid(string s)
{
    string open = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            open.push_back(s[i]);
        }
        else
        {
            if ((s[i] == ')' && open.back() == '(') || (s[i] == ']' && open.back() == '[') || (s[i] == '}' && open.back() == '{'))
            {
                open.pop_back();
            }else{
                return false;
            }
        }
    }
    return open.empty();
}